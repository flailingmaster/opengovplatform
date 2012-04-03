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
-- Table structure for table `content_type_catalog_type_document`
--

DROP TABLE IF EXISTS `content_type_catalog_type_document`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `content_type_catalog_type_document` (
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `field_ctd_catalog_location_value` longtext,
  `field_ctd_classification_value` longtext,
  `field_ctd_target_audience_value` longtext,
  `field_ctd_validity_date_value` int(11) DEFAULT NULL,
  `field_ctd_frequency_value` longtext,
  `field_ctd_language_value` longtext,
  `field_ctd_dataset_group_name_value` longtext,
  PRIMARY KEY (`vid`),
  KEY `nid` (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `content_type_catalog_type_document`
--

LOCK TABLES `content_type_catalog_type_document` WRITE;
/*!40000 ALTER TABLE `content_type_catalog_type_document` DISABLE KEYS */;
INSERT IGNORE INTO `content_type_catalog_type_document` VALUES (890,280,'Internal','Form','public',NULL,'annual','english',NULL),(955,286,'External','Scheme','All',NULL,'monthly','English',NULL),(958,284,'External','Annual Report','Consumers',NULL,'annual','English',NULL),(13468,478,'Internal','Annual Report','All',NULL,NULL,'English',NULL),(15348,1224,'Internal','Rule','public',NULL,'annual','English',NULL);
/*!40000 ALTER TABLE `content_type_catalog_type_document` ENABLE KEYS */;
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
