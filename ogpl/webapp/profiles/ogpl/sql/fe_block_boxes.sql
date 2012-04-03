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
-- Table structure for table `fe_block_boxes`
--

DROP TABLE IF EXISTS `fe_block_boxes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `fe_block_boxes` (
  `bid` int(10) unsigned NOT NULL DEFAULT '0',
  `machine_name` varchar(32) NOT NULL DEFAULT '',
  PRIMARY KEY (`bid`),
  KEY `machine_name` (`machine_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `fe_block_boxes`
--

LOCK TABLES `fe_block_boxes` WRITE;
/*!40000 ALTER TABLE `fe_block_boxes` DISABLE KEYS */;
INSERT IGNORE INTO `fe_block_boxes` VALUES (5,'heading_new_features'),(6,'heading_rss_feeds'),(7,'new_features'),(8,'newest_dataset_contentimage'),(9,'newest_dataset_heading'),(10,'rss_feeds_html'),(11,'whats_new_content'),(12,'whats_new_title'),(13,'whatsnew_news'),(20,'gallery_content'),(21,'gallery_header'),(23,'welcome_block_header'),(25,'filter_header'),(26,'popular_apps_catalog'),(27,'popular_dataset_catalog'),(28,'popular_document_catalog'),(29,'recent_apps_catalog'),(30,'recent_dataset_catalog'),(31,'recent_document_catalog'),(32,'majorevents'),(34,'dataset_search_options'),(35,'cms_notification_alert'),(37,'cmsadmin_workflow_summary'),(38,'vrm_feedback_summary');
/*!40000 ALTER TABLE `fe_block_boxes` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-03-23 11:06:27
