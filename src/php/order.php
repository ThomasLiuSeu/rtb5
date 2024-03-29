<?php header('Access-Control-Allow-Origin:*');
    $mysql_server_name="localhost"; //数据库服务器名称
    $mysql_username="root"; // 连接数据库用户名
    $mysql_password="abcdefg2008"; // 连接数据库密码
    $mysql_database="rtb5"; // 数据库的名字
    $ret=array();
    $ret_status=array();
    $token= $_GET["token"] ;
    if (!empty($token )) 
    {
       $decode = base64_decode($token);
       if (is_numeric($decode )) 
      {
         $user_id = $decode & 0x0000ffff;
         if ($token != base64_encode(base_convert(md5($user_id), 16, 10 )  & 0xffff0000 + $user_id)) 
         {
          $ret_status["error_code"]=1005;
          $ret_status["msg"]="Token check error";
          array_push($ret,$ret_status);
          echo json_encode($ret);
          exit ();
        }
      } else {
        $ret_status["error_code"]=1006;
        $ret_status["msg"]="Token is not correct";
        array_push($ret,$ret_status);
        echo json_encode($ret);
        exit ();
      }
    } else {
        $ret_status["error_code"]=1007;
        $ret_status["msg"]="Token is  empty";
        array_push($ret,$ret_status);
        echo json_encode($ret);
        exit ();
   }

    if (!is_numeric($user_id )) 
    {
        $ret_status["error_code"]=1000;
        $ret_status["msg"]="User id is not correct";
        array_push($ret,$ret_status);
        echo json_encode($ret);
        exit();
    }
    $status = $_GET["status"] ;
    if (!is_numeric($status ) && $status != "") 
    {
        $ret_status["error_code"]=1001;
        $ret_status["msg"]="Status is not correct";
        $ret["status"]=$ret_status;
        echo json_encode($ret);
        exit();
    }
    $begin_time = $_GET["begin_time"] ;
    if (!is_numeric($begin_time ) && $begin_time != "") 
    {
        $ret_status["error_code"]=1002;
        $ret_status["msg"]="Begin time is not correct";
        array_push($ret,$ret_status);
        echo json_encode($ret);
        exit();
    }
    $end_time = $_GET["end_time"] ;
    if (!is_numeric($end_time )  && $end_time != "") 
    {
        $ret_status["error_code"]=-1003;
        $ret_status["msg"]="End time is not correct";
        array_push($ret,$ret_status);
        echo json_encode($ret);
        exit();
    }
    $tags=$_GET["tags"] ;
    // 连接到数据库
    $conn=mysql_connect($mysql_server_name, $mysql_username, $mysql_password);

     // 从表中提取信息的sql语句
    $strsql="SELECT user_id, order_id, tags, campaign_id, origin_url, trading_volume, cash_back, order_time, valid_time, currency_type, status FROM `click` INNER JOIN `order` ON click.click_id = order.click_id where user_id=".$user_id;
    if ($tags != "") 
    {
        $strsql = $strsql." and tags=\"".$tags."\"";
    }
    if ($status != "") 
    {
        $strsql = $strsql." and status=\"".$status."\"";
    }
    if ($begin_time != "") 
    {
        $strsql = $strsql." and order_time>\"".$begin_time."\"";
    }
    if ($end_time != "") 
    {
        $strsql = $strsql." and order_time<\"".$end_time."\"";
    }
    // 执行sql查询
    $result=mysql_db_query($mysql_database, $strsql, $conn);
    // 获取查询结果
    $row=mysql_fetch_row($result);
    
    $data=array();
    // 定位到第一条记录
    mysql_data_seek($result, 0);
    // 循环取出记录
    while ($row=mysql_fetch_row($result))
    {
      $record=array();
      for ($i=0; $i<mysql_num_fields($result); $i++ )
      {
        $record[mysql_field_name($result, $i)]=$row[$i];
      }
      array_push($data,$record);
    }
    $ret_status["error_code"]=0;
    $ret_status["msg"]="Suceess";
    $ret["status"] = $ret_status;
    $ret["data"] = $data;
    echo json_encode($ret);
    // 释放资源
    mysql_free_result($result);
    // 关闭连接
    mysql_close($conn);  
?>
