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
-- Table structure for table `webform_component`
--

DROP TABLE IF EXISTS `webform_component`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `webform_component` (
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `cid` smallint(5) unsigned NOT NULL DEFAULT '0',
  `pid` smallint(5) unsigned NOT NULL DEFAULT '0',
  `form_key` varchar(128) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `type` varchar(16) DEFAULT NULL,
  `value` text NOT NULL,
  `extra` text NOT NULL,
  `mandatory` tinyint(4) NOT NULL DEFAULT '0',
  `weight` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`nid`,`cid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `webform_component`
--

LOCK TABLES `webform_component` WRITE;
/*!40000 ALTER TABLE `webform_component` DISABLE KEYS */;
INSERT IGNORE INTO `webform_component` VALUES (101,1,0,'contactus_subject','Subject','textfield','','a:13:{s:13:\"title_display\";s:6:\"before\";s:7:\"private\";i:0;s:8:\"disabled\";i:0;s:6:\"unique\";i:0;s:20:\"conditional_operator\";s:1:\"=\";s:5:\"width\";s:0:\"\";s:9:\"maxlength\";s:0:\"\";s:12:\"field_prefix\";s:0:\"\";s:12:\"field_suffix\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}s:21:\"conditional_component\";s:0:\"\";s:18:\"conditional_values\";s:0:\"\";}',1,7),(101,2,0,'contactus_message','Message','textarea','','a:11:{s:13:\"title_display\";i:0;s:7:\"private\";i:0;s:9:\"resizable\";i:1;s:8:\"disabled\";i:0;s:20:\"conditional_operator\";s:1:\"=\";s:4:\"cols\";s:0:\"\";s:4:\"rows\";s:0:\"\";s:11:\"description\";s:0:\"\";s:10:\"attributes\";a:0:{}s:21:\"conditional_component\";s:0:\"\";s:18:\"conditional_values\";s:0:\"\";}',1,8),(101,3,0,'email_address','Email','email','%useremail','a:5:{s:13:\"title_display\";s:6:\"before\";s:7:\"private\";i:0;s:8:\"disabled\";i:1;s:6:\"unique\";i:0;s:20:\"conditional_operator\";s:1:\"=\";}',0,6),(101,4,0,'contactus_user','User','textfield','%username','a:5:{s:13:\"title_display\";s:6:\"before\";s:7:\"private\";i:1;s:8:\"disabled\";i:1;s:6:\"unique\";i:0;s:20:\"conditional_operator\";s:1:\"=\";}',0,5);
/*!40000 ALTER TABLE `webform_component` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-03-23 11:06:32
