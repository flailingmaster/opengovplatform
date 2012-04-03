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
-- Table structure for table `content_type_catalog_type_data_service`
--

DROP TABLE IF EXISTS `content_type_catalog_type_data_service`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `content_type_catalog_type_data_service` (
  `vid` int(10) unsigned NOT NULL DEFAULT '0',
  `nid` int(10) unsigned NOT NULL DEFAULT '0',
  `field_ctds_service_maturity_value` longtext,
  `field_ctds_service_category_value` longtext,
  `field_ctds_datasets_used_value` longtext,
  `field_ctds_target_audience_value` longtext,
  `field_ctds_language_value` longtext,
  `field_ctds_access_type_value` longtext,
  PRIMARY KEY (`vid`),
  KEY `nid` (`nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `content_type_catalog_type_data_service`
--

LOCK TABLES `content_type_catalog_type_data_service` WRITE;
/*!40000 ALTER TABLE `content_type_catalog_type_data_service` DISABLE KEYS */;
INSERT IGNORE INTO `content_type_catalog_type_data_service` VALUES (13256,429,'Information','Check','Raw data','Young','English','Open Access'),(13279,431,'Information','Obtain','raw datasets','young','english','Open Access'),(17808,2342,'Please select','Please select',NULL,NULL,NULL,NULL),(17842,2350,'Information','Apply','http://203.199.26.72/ogpl_live/node/2350/edit/2','Anonymous','English','Open Access'),(17864,2351,'Information','Apply','http://203.199.26.72/ogpl_live/node/2350/edit/2','Anonymous','English','Open Access'),(17891,2357,'Information','Apply','http://203.199.26.72/ogpl_live/node/2350/edit/2','Anonymous','English','Open Access');
/*!40000 ALTER TABLE `content_type_catalog_type_data_service` ENABLE KEYS */;
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
