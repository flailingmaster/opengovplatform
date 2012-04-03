-- MySQL dump 10.13  Distrib 5.1.58, for redhat-linux-gnu (i686)
--
-- Host: localhost    Database: ogpl_live
-- ------------------------------------------------------
-- Server version	5.1.58-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `content_type_feedback`
--

DROP TABLE IF EXISTS `content_type_feedback`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `content_type_feedback` (
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `field_assigned_to_uid` int(10) unsigned DEFAULT NULL,
  `field_delay_time_value` int(11) DEFAULT NULL,
  `field_email_email` varchar(255) DEFAULT NULL,
  `field_feedback_subject_value` longtext,
  `field_refer_nodeid_value` int(11) DEFAULT NULL,
  `field_action_status_value` int(11) DEFAULT NULL,
  `field_sender_name_value` varchar(60) DEFAULT NULL,
  `field_agency_value` int(11) DEFAULT NULL,
  `field_forwarded_to_nonmembers_value` longtext,
  `field_source_value` int(11) DEFAULT NULL,
  `field_feedback_body_value` longtext,
  `field_feedback_priority_value` int(11) DEFAULT NULL,
  `field_feedback_assigner_uid` int(10) unsigned DEFAULT NULL,
  `field_feed_orig_action_status_value` int(11) DEFAULT NULL,
  PRIMARY KEY (`vid`),
  KEY `nid` (`nid`),
  KEY `field_assigned_to_uid` (`field_assigned_to_uid`),
  KEY `field_feedback_assigner_uid` (`field_feedback_assigner_uid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `content_type_feedback`
--

LOCK TABLES `content_type_feedback` WRITE;
/*!40000 ALTER TABLE `content_type_feedback` DISABLE KEYS */;
INSERT IGNORE INTO `content_type_feedback` VALUES (17913,2369,88,1,NULL,'Contact Us Contact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContact UsContaLast',1179,1,'Contact Us',440,'ineethi@gmail.com',12,'Contact Us\r\nThe answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open Government Platform is welcome to serve you better.The answer you entered for the Verification field was not correct.\r\n\r\nYour valuable feedback on Open',0,88,1),(17914,2370,NULL,1,NULL,NULL,282,NULL,NULL,NULL,NULL,14,'National Stock Number extract includes the current listing of National Stock Numbers (NSNs), NSN item name and descriptions, and current selling price of each product listed in GSA Advantage and managed by GSA for use by the general public. This list contains only stocked items in the GSA Supply Chain and does not list nonstocked items.Each NSN is listed with the vendors description of the item. Some descriptions exceed the standard length and are truncated.',0,NULL,NULL),(17915,2371,NULL,1,NULL,NULL,653,NULL,'Suggest Dataset',NULL,NULL,15,'Suggest Dataset',0,NULL,NULL),(17916,2372,88,1,'ineethi@gmail.com',NULL,653,3,'Suggest Dataset',440,NULL,15,'Suggest Dataset',0,88,NULL),(17917,2373,89,1,NULL,NULL,427,72,NULL,440,NULL,14,'Denied Persons List with Denied US Export Privileges\r\n\r\nRatings!!!!!!!!!!!!!!!',0,88,NULL),(17918,2374,90,1,NULL,NULL,651,3,'Feedback',440,NULL,13,'Feedback',0,88,3);
/*!40000 ALTER TABLE `content_type_feedback` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-03-23 11:06:26
