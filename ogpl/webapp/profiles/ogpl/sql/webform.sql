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
-- Table structure for table `webform`
--

DROP TABLE IF EXISTS `webform`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `webform` (
  `nid` int(10) unsigned NOT NULL,
  `confirmation` text NOT NULL,
  `confirmation_format` tinyint(4) NOT NULL DEFAULT '0',
  `redirect_url` varchar(255) DEFAULT '<confirmation>',
  `status` tinyint(4) NOT NULL DEFAULT '1',
  `block` tinyint(4) NOT NULL DEFAULT '0',
  `teaser` tinyint(4) NOT NULL DEFAULT '0',
  `allow_draft` tinyint(4) NOT NULL DEFAULT '0',
  `auto_save` tinyint(4) NOT NULL DEFAULT '0',
  `submit_notice` tinyint(4) NOT NULL DEFAULT '1',
  `submit_text` varchar(255) DEFAULT NULL,
  `submit_limit` tinyint(4) NOT NULL DEFAULT '-1',
  `submit_interval` int(11) NOT NULL DEFAULT '-1',
  `total_submit_limit` int(11) NOT NULL DEFAULT '-1',
  `total_submit_interval` int(11) NOT NULL DEFAULT '-1',
  PRIMARY KEY (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `webform`
--

LOCK TABLES `webform` WRITE;
/*!40000 ALTER TABLE `webform` DISABLE KEYS */;
INSERT IGNORE INTO `webform` VALUES (101,'<p>Thank you for contacting the Open Government Platform. We will respond to you as soon as possible. Have a great day!</p>',1,'<confirmation>',1,0,0,0,0,1,'Submit this form!',-1,-1,-1,-1);
/*!40000 ALTER TABLE `webform` ENABLE KEYS */;
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
