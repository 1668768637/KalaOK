/*
Navicat MySQL Data Transfer

Source Server         : mysql
Source Server Version : 80027
Source Host           : localhost:3306
Source Database       : ruanjian

Target Server Type    : MYSQL
Target Server Version : 80027
File Encoding         : 65001

Date: 2022-05-19 23:53:41
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `song`
-- ----------------------------
DROP TABLE IF EXISTS `song`;
CREATE TABLE `song` (
  `song` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `singer` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `browseNums` int NOT NULL,
  PRIMARY KEY (`song`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- ----------------------------
-- Records of song
-- ----------------------------
INSERT INTO `song` VALUES ('love story', '泰勒.斯威夫特', '2');
INSERT INTO `song` VALUES ('七里香', '周杰伦', '9');
INSERT INTO `song` VALUES ('不为谁而作的歌', '林俊杰', '0');
INSERT INTO `song` VALUES ('光年之外', '邓紫棋', '11');
INSERT INTO `song` VALUES ('双截棍', '周杰伦', '2');
INSERT INTO `song` VALUES ('可惜没如果', '林俊杰', '13');
INSERT INTO `song` VALUES ('方圆几里', '薛之谦', '19');
INSERT INTO `song` VALUES ('晴天', '周杰伦', '1');
INSERT INTO `song` VALUES ('李白', '李荣浩', '29');
INSERT INTO `song` VALUES ('模特', '李荣浩', '2');
INSERT INTO `song` VALUES ('江南', '林俊杰', '21');
INSERT INTO `song` VALUES ('泡沫', '邓紫棋', '0');
INSERT INTO `song` VALUES ('演员', '薛之谦', '0');
INSERT INTO `song` VALUES ('爱情转移', '陈奕迅', '0');
INSERT INTO `song` VALUES ('蒲公英的约定', '周杰伦', '1');
