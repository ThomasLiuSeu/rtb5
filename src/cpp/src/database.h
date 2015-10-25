#ifndef SRC_DATABASE_H
#define SRC_DATABASE_H

#include <string>
#include <list>
#include <mysql/mysql.h>
#include <mutex>
#include <thread>
#include <glog/logging.h>
#include <boost/lexical_cast.hpp>
#include "proto/click.pb.h"
#include "proto/campaign.pb.h"
#include "proto/union.pb.h"
#include "proto/user.pb.h"
#include "proto/order.pb.h"
#include "proto/order.grpc.pb.h"

namespace RTB5 {

class Database {
 public:
  //
  bool Open();
  //
  void Close();
  // 
  template <typename Record>
  bool Insert(const Record& record) {
    std::string table;
    std::map<std::string, std::string> parameters;
    if (!GenerateParameters(record, &table, &parameters)) {
      return false;
    }
    std::string sql = GenerateInsertSql(table, parameters);
    std::vector<std::map<std::string, std::string> > results;
    return Exec(sql, &results);
  }
  //
  template <typename Record>
  bool Load(std::vector<Record>* records) {
    std::string sql = GenerateSelectSql<Record>();
    std::vector<std::map<std::string, std::string> > results;
    if (!Exec(sql, &results)) {
      return false;
    }
    for (const auto& result : results) {
      Record record;
      ParseSqlResult(result, &record);
      records->push_back(record); 
    }
    return true;
  }
  //
  bool Load(const OrderRequest& order_request, std::vector<Order>* orders) {
    std::string sql = GenerateSelectSql<Order>();
    std::vector<std::map<std::string, std::string> > results;
    sql += GenerateConditionSql(order_request);
    LOG(ERROR) << sql;
    if (!Exec(sql, &results)) {
      return false;
    }
    for (const auto& result : results) {
      Order order;
      ParseSqlResult(result, &order);
      orders->push_back(order); 
    }
    return true;
  }
  // 
  bool Query(uint64_t click_id, Click* click);
  //
  bool Query(uint64_t order_id, Order* order);
  //
  bool Query(uint64_t campaign_id, Campaign* campaign);
  //
  bool Query(uint64_t user_id, User* user);
  //
  std::string GenerateConditionSql(const OrderRequest& order_request) {
    std::string sql = " where ";
    bool first_conditon = true;
    if (order_request.user_id() != 0) {
      first_conditon = false;
      sql += " user_id=" + boost::lexical_cast<std::string>(order_request.user_id());
    }
    if (order_request.begin_time() != 0) {
      if (!first_conditon) {
        sql += " and";
      }
      first_conditon = false;
      sql += " order_time>" + boost::lexical_cast<std::string>(order_request.begin_time());
    }
    if (order_request.end_time() != 0) {
      if (!first_conditon) {
        sql += " and";
      }
      first_conditon = false;
      sql += " order_time<" + boost::lexical_cast<std::string>(order_request.end_time());
    }
    if (order_request.tags() != "") {
      if (!first_conditon) {
        sql += " and";
      }
      first_conditon = false;
      sql += " tags=" + order_request.tags();
    }
    return sql;
  }

 private:
  //
  bool Exec(const std::string& sql, std::vector< std::map<std::string, std::string> >* results);
  //
  bool FetchRows(MYSQL* db, std::vector< std::map<std::string, std::string> >* rows);
  //
  std::string GenerateInsertSql(const std::string& table, const std::map<std::string, std::string>& parameters);
  //
  template <typename Record>
  std::string GenerateSelectSql() {
    std::string table = "";
    if (std::is_same<Record, Union>::value) {
      table = "`union`";
    } else if (std::is_same<Record, Campaign>::value){
      table = "`campaign`";     
    } else if (std::is_same<Record, Click>::value){
      table = "`click`";
    } else if (std::is_same<Record, Order>::value){
      table = " `click` INNER JOIN `order` ON click.click_id = order.click_id ";
    }
    std::string sql;
    sql += "SELECT * FROM " + table;
    return sql;
  }
  //
  bool GenerateParameters(const Campaign& campaign, std::string* table, std::map<std::string, std::string>* parameters);
  //
  bool GenerateParameters(const Click& click, std::string* table, std::map<std::string, std::string>* parameters);
  //
  bool GenerateParameters(const Union& uppper_union, std::string* table, std::map<std::string, std::string>* parameters);
  //
  bool GenerateParameters(const User& user, std::string* table, std::map<std::string, std::string>* parameters);
  //
  bool GenerateParameters(const Order& order, std::string* table, std::map<std::string, std::string>* parameters);
  //
  bool ParseSqlResult(const std::map<std::string, std::string>& parameters, Union* upper_union);
  //
  bool ParseSqlResult(const std::map<std::string, std::string>& parameters, Campaign* campaign);
  //
  bool ParseSqlResult(const std::map<std::string, std::string>& parameters, Order* order);
  //
  bool ParseSqlResult(const std::map<std::string, std::string>& parameters, Click* click);

 private:
  //
  MYSQL* rtb5;
  //
  std::mutex db_mutex; 
};

} // RTB5

#endif // SRC_DATABASE_H
