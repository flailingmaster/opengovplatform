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
-- Table structure for table `workflow_transitions`
--

DROP TABLE IF EXISTS `workflow_transitions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `workflow_transitions` (
  `tid` int(11) NOT NULL AUTO_INCREMENT,
  `sid` int(10) unsigned NOT NULL DEFAULT '0',
  `target_sid` int(10) unsigned NOT NULL DEFAULT '0',
  `roles` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`tid`),
  KEY `sid` (`sid`),
  KEY `target_sid` (`target_sid`)
) ENGINE=InnoDB AUTO_INCREMENT=103 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `workflow_transitions`
--

LOCK TABLES `workflow_transitions` WRITE;
/*!40000 ALTER TABLE `workflow_transitions` DISABLE KEYS */;
INSERT IGNORE INTO `workflow_transitions` VALUES (1,3,4,'author,4,3,5,6'),(2,4,5,'3'),(3,4,6,'5,4'),(5,5,4,'5'),(6,5,6,'5,3,6'),(8,6,5,'4,6'),(9,6,7,'4'),(11,7,5,'6'),(12,7,6,'6'),(26,7,10,'6'),(27,4,7,'6'),(28,4,10,'6'),(29,5,10,'6'),(30,6,10,'6'),(32,16,17,'author,18,12,13,10'),(36,17,18,'11,12,10,18'),(37,18,17,'12,10,18'),(39,18,22,'12,10,18'),(40,22,18,'13,10,18'),(41,22,19,'13,10'),(57,19,17,'11,18,12,13,10'),(58,17,22,'12,10,18'),(61,22,17,'13,10,18'),(62,19,18,'12,10,18'),(64,16,18,'10'),(65,16,22,'10'),(66,16,19,'10'),(67,16,24,'10'),(68,17,19,'10'),(69,17,24,'10'),(70,18,19,'10'),(71,18,24,'10'),(72,22,24,'10'),(73,19,22,'10,18'),(74,19,24,'10'),(75,24,17,'18'),(76,24,18,'18'),(77,24,22,'18'),(78,25,26,'author,15'),(79,26,27,'15'),(80,26,34,'15'),(83,27,30,'6,14,15,4'),(85,28,32,'15'),(86,28,33,'15'),(88,29,32,'15'),(89,29,33,'15'),(91,30,27,'15'),(101,32,27,'15'),(102,33,27,'15');
/*!40000 ALTER TABLE `workflow_transitions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-03-23 11:06:33
