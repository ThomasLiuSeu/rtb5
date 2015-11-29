CREATE DATABASE IF NOT EXISTS rtb5;
use rtb5;

CREATE TABLE IF NOT EXISTS `user` (
`user_id` BIGINT( 11 ) NOT NULL,
`user_name` VARCHAR( 255 ) NOT NULL,
`account` VARCHAR( 255 ) ,
`password` VARCHAR( 255 ) NOT NULL,
`token` VARCHAR( 255 ) NOT NULL,
`user_ext` BLOB,
 PRIMARY KEY(`user_id`),
 UNIQUE (`token`) 
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 ;

CREATE TABLE IF NOT EXISTS `union` (
`union_id` BIGINT( 11 ) NOT NULL,
`union_name` VARCHAR( 255 ) NOT NULL,
`url_pattern` VARCHAR( 255 ) NOT NULL,
`union_ext` BLOB,
 PRIMARY KEY(`union_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 ;

CREATE TABLE IF NOT EXISTS `campaign` (
`campaign_id` BIGINT( 11 ) NOT NULL,
`campaign_name` VARCHAR( 255 ) NOT NULL,
`pattern` VARCHAR( 255 ) NOT NULL,
`union_id` BIGINT( 11 ) NOT NULL,
`percent` FLOAT( 11 ) NOT NULL,
 PRIMARY KEY(`campaign_id`),
 FOREIGN KEY (`union_id`)  REFERENCES `union`(`union_id`)
 ) ENGINE=InnoDB  DEFAULT CHARSET=utf8 ;

CREATE TABLE IF NOT EXISTS `click` (
`click_id` BIGINT( 11 ) NOT NULL,
`user_id` BIGINT( 11 ) NOT NULL,
`union_id` BIGINT( 11 ) NOT NULL,
`campaign_id` BIGINT( 11 ) NOT NULL,
`click_time` BIGINT( 11 ) NOT NULL,
`origin_url` VARCHAR(255) ,
`second_jump_url` VARCHAR(255) ,
`tags` VARCHAR(255) ,
`ip` VARCHAR(255) ,
 PRIMARY KEY(`click_id`),
 FOREIGN KEY (`user_id`)  REFERENCES `user`(`user_id`),
 FOREIGN KEY (`union_id`)  REFERENCES `union`(`union_id`),
 FOREIGN KEY (`campaign_id`)  REFERENCES `campaign`(`campaign_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 ;

CREATE TABLE IF NOT EXISTS `order` (
`order_id` BIGINT( 11 ) NOT NULL,
`status` BIGINT( 11 ) NOT NULL,
`click_id` BIGINT( 11 ) NOT NULL,
`cash_back` BIGINT( 11 ) ,
`commission` BIGINT( 11 ) ,
`trading_volume` BIGINT( 11 ) NOT NULL,
`order_time` BIGINT( 11 ) ,
`valid_time` BIGINT( 11 ),
`currency_type` VARCHAR(255)  DEFAULT NULL,
 PRIMARY KEY(`order_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 

