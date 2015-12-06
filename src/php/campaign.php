<?php header('Access-Control-Allow-Origin:*');
    $mysql_server_name="localhost"; //数据库服务器名称
    $mysql_username="root"; // 连接数据库用户名
    $mysql_password="abcdefg2008"; // 连接数据库密码
    $mysql_database="rtb5"; // 数据库的名字
    $mod = $_GET["mod"] ;
    $campaign_id = $_GET["campaign_id"] ;
    $campaign_name = $_GET["campaign_name"] ;
    $pattern = $_GET["pattern"] ;
    $union_id = $_GET["union_id"] ;
    $percent = $_GET["percent"] ;

    if (!is_numeric($campaign_id )) 
    {
        echo "Campaign id is not correct:".$campaign_id;
        exit();
    }
    if (!is_numeric($union_id )) 
    {
        echo "Union id is not correct:".$union_id;
        exit();
    }
    if ($mod != "insert" && $mod != "update"  && $mod != "delete") 
    {
        echo "Mod is not correct:".$campaign_id;
        exit();
    }
    if ($mod != "insert" && $mod != "update"  && $mod != "delete") 
    {
        echo "Mod is not correct:".$campaign_id;
        exit();
    }
    $conn=mysql_connect($mysql_server_name, $mysql_username,
                        $mysql_password);
    if(!$conn){
      die("连接失败".mysql_error());
    }
     // 从表中提取信息的sql语句 TODO(cernwang@tencent.com)
    if ()
    {
       $strsql="INSERT INTO `campaign`  values(".$campaign_id.",".$campaign_name.",".$pattern.",".$union_id.",".$percent.")";     
   } else {
       $strsql="UPDATE `campaign`  SET values(".$campaign_id.",".$campaign_name.",".$pattern.",".$union_id.",".$percent.")";        
   }

    // 执行sql查询
    $result=mysql_db_query($mysql_database, $strsql, $conn);
    // 获取查询结果
    $row=mysql_fetch_row($result);
    // 释放资源
    mysql_free_result($result);
    // 关闭连接
    mysql_close($conn);  
?>
