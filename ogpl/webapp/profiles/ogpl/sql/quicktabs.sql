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
-- Table structure for table `quicktabs`
--

DROP TABLE IF EXISTS `quicktabs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `quicktabs` (
  `machine_name` varchar(255) NOT NULL,
  `ajax` int(10) unsigned NOT NULL DEFAULT '0',
  `hide_empty_tabs` int(10) unsigned NOT NULL DEFAULT '0',
  `default_tab` tinyint(3) unsigned NOT NULL,
  `title` varchar(255) NOT NULL,
  `tabs` mediumtext NOT NULL,
  `style` varchar(255) NOT NULL,
  PRIMARY KEY (`machine_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `quicktabs`
--

LOCK TABLES `quicktabs` WRITE;
/*!40000 ALTER TABLE `quicktabs` DISABLE KEYS */;
INSERT IGNORE INTO `quicktabs` VALUES ('catalog_tab',0,0,0,'Front End Home Page Rotating Tabs','a:3:{i:0;a:7:{s:3:\"vid\";s:19:\"Most_Recent_Catalog\";s:7:\"display\";s:7:\"block_1\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_0\";s:5:\"title\";s:15:\"Recent Catalogs\";s:6:\"weight\";s:4:\"-100\";s:4:\"type\";s:4:\"view\";}i:1;a:7:{s:3:\"vid\";s:20:\"Most_Popular_Catalog\";s:7:\"display\";s:7:\"block_1\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_1\";s:5:\"title\";s:16:\"Popular Catalogs\";s:6:\"weight\";s:3:\"-99\";s:4:\"type\";s:4:\"view\";}i:2;a:5:{s:3:\"bid\";s:27:\"web_feed_aggregator_delta_0\";s:10:\"hide_title\";i:1;s:5:\"title\";s:12:\"Major Events\";s:6:\"weight\";s:3:\"-98\";s:4:\"type\";s:5:\"block\";}}','Zen'),('vrm_admin_tabs_delay_time',0,0,0,'Vrm Admin Tabs Delay Time','a:2:{i:0;a:4:{s:4:\"path\";s:17:\"manage/delay/time\";s:5:\"title\";s:17:\"Manage Delay Time\";s:6:\"weight\";s:4:\"-100\";s:4:\"type\";s:8:\"callback\";}i:1;a:7:{s:3:\"vid\";s:21:\"vrm_admin_actions_log\";s:7:\"display\";s:6:\"page_3\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_1\";s:5:\"title\";s:7:\"History\";s:6:\"weight\";s:3:\"-99\";s:4:\"type\";s:4:\"view\";}}','default'),('vrm_admin_tabs_list',0,0,1,'Vrm Admin Tabs List','a:10:{i:0;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_1\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_0\";s:5:\"title\";s:3:\"All\";s:6:\"weight\";s:4:\"-100\";s:4:\"type\";s:4:\"view\";}i:1;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_7\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_1\";s:5:\"title\";s:7:\"My List\";s:6:\"weight\";s:3:\"-99\";s:4:\"type\";s:4:\"view\";}i:2;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_3\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_2\";s:5:\"title\";s:6:\"Opened\";s:6:\"weight\";s:3:\"-98\";s:4:\"type\";s:4:\"view\";}i:3;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_4\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_3\";s:5:\"title\";s:8:\"Assigned\";s:6:\"weight\";s:3:\"-97\";s:4:\"type\";s:4:\"view\";}i:4;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_5\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_4\";s:5:\"title\";s:7:\"Replied\";s:6:\"weight\";s:3:\"-96\";s:4:\"type\";s:4:\"view\";}i:5;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_6\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_5\";s:5:\"title\";s:8:\"Reviewed\";s:6:\"weight\";s:3:\"-95\";s:4:\"type\";s:4:\"view\";}i:6;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:7:\"page_13\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_6\";s:5:\"title\";s:8:\"Reverted\";s:6:\"weight\";s:3:\"-94\";s:4:\"type\";s:4:\"view\";}i:7;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:7:\"page_16\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_7\";s:5:\"title\";s:6:\"Closed\";s:6:\"weight\";s:3:\"-93\";s:4:\"type\";s:4:\"view\";}i:8;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:7:\"page_15\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_8\";s:5:\"title\";s:8:\"Archived\";s:6:\"weight\";s:3:\"-92\";s:4:\"type\";s:4:\"view\";}i:9;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:7:\"page_17\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_9\";s:5:\"title\";s:10:\"Irrelevant\";s:6:\"weight\";s:3:\"-91\";s:4:\"type\";s:4:\"view\";}}','nostyle'),('vrm_admin_tabs_status',0,0,0,'Vrm Admin Tabs Status','a:2:{i:0;a:7:{s:3:\"vid\";s:17:\"vrm_category_view\";s:7:\"display\";s:6:\"page_3\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_0\";s:5:\"title\";s:6:\"Status\";s:6:\"weight\";s:4:\"-100\";s:4:\"type\";s:4:\"view\";}i:1;a:7:{s:3:\"vid\";s:21:\"vrm_admin_actions_log\";s:7:\"display\";s:6:\"page_4\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_1\";s:5:\"title\";s:7:\"History\";s:6:\"weight\";s:3:\"-99\";s:4:\"type\";s:4:\"view\";}}','default'),('vrm_manage_actions',0,0,0,'Vrm Manage Actions','a:3:{i:0;a:7:{s:3:\"vid\";s:17:\"vrm_category_view\";s:7:\"display\";s:6:\"page_2\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_0\";s:5:\"title\";s:4:\"List\";s:6:\"weight\";s:4:\"-100\";s:4:\"type\";s:4:\"view\";}i:1;a:4:{s:4:\"path\";s:18:\"manage/add/actions\";s:5:\"title\";s:3:\"Add\";s:6:\"weight\";s:3:\"-99\";s:4:\"type\";s:8:\"callback\";}i:2;a:7:{s:3:\"vid\";s:21:\"vrm_admin_actions_log\";s:7:\"display\";s:6:\"page_2\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_2\";s:5:\"title\";s:7:\"History\";s:6:\"weight\";s:3:\"-98\";s:4:\"type\";s:4:\"view\";}}','default'),('vrm_manage_categories',0,0,0,'Vrm Manage Categories','a:3:{i:0;a:7:{s:3:\"vid\";s:17:\"vrm_category_view\";s:7:\"display\";s:6:\"page_1\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_0\";s:5:\"title\";s:4:\"List\";s:6:\"weight\";s:4:\"-100\";s:4:\"type\";s:4:\"view\";}i:1;a:4:{s:4:\"path\";s:21:\"manage/add/categories\";s:5:\"title\";s:3:\"Add\";s:6:\"weight\";s:3:\"-99\";s:4:\"type\";s:8:\"callback\";}i:2;a:7:{s:3:\"vid\";s:21:\"vrm_admin_actions_log\";s:7:\"display\";s:6:\"page_1\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_2\";s:5:\"title\";s:7:\"History\";s:6:\"weight\";s:3:\"-98\";s:4:\"type\";s:4:\"view\";}}','default'),('vrm_pmo_tabs_list',0,0,0,'Vrm PMO Tabs List','a:7:{i:0;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_2\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_0\";s:5:\"title\";s:7:\"My List\";s:6:\"weight\";s:4:\"-100\";s:4:\"type\";s:4:\"view\";}i:1;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_8\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_1\";s:5:\"title\";s:9:\"Forwarded\";s:6:\"weight\";s:3:\"-99\";s:4:\"type\";s:4:\"view\";}i:2;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:6:\"page_9\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_2\";s:5:\"title\";s:8:\"Assigned\";s:6:\"weight\";s:3:\"-98\";s:4:\"type\";s:4:\"view\";}i:3;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:7:\"page_10\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_3\";s:5:\"title\";s:7:\"Replied\";s:6:\"weight\";s:3:\"-97\";s:4:\"type\";s:4:\"view\";}i:4;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:7:\"page_11\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_4\";s:5:\"title\";s:8:\"Reviewed\";s:6:\"weight\";s:3:\"-96\";s:4:\"type\";s:4:\"view\";}i:5;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:7:\"page_12\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_5\";s:5:\"title\";s:8:\"Archived\";s:6:\"weight\";s:3:\"-95\";s:4:\"type\";s:4:\"view\";}i:6;a:7:{s:3:\"vid\";s:21:\"VRM_all_feedback_list\";s:7:\"display\";s:7:\"page_18\";s:4:\"args\";s:0:\"\";s:12:\"get_displays\";s:7:\"vdisp_6\";s:5:\"title\";s:6:\"Closed\";s:6:\"weight\";s:3:\"-94\";s:4:\"type\";s:4:\"view\";}}','nostyle');
/*!40000 ALTER TABLE `quicktabs` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-03-23 11:06:30
