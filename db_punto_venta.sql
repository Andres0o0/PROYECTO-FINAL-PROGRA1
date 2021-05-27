-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: localhost    Database: db_punto_venta
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `clientes`
--

DROP TABLE IF EXISTS `clientes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `clientes` (
  `idCliente` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `nit` varchar(12) DEFAULT NULL,
  `genero` bit(1) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `correo_electronico` varchar(45) DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idCliente`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `clientes`
--

LOCK TABLES `clientes` WRITE;
/*!40000 ALTER TABLE `clientes` DISABLE KEYS */;
INSERT INTO `clientes` VALUES (5,'MIRIAM','JUAREZ','8990',_binary '','4242','miriam@gmail.com','2021-04-15 19:59:57'),(6,'MARTA','CERVANTES','8991',_binary '','4243','marta@gmail.com','2021-04-15 20:01:22'),(7,'ANTONIO','PEREZ','8992',_binary '\0','4244','antonio@gmail.com','2021-04-15 20:02:16'),(8,'YAKSY','MEJILLA','8993',_binary '','4245','yaksy@gmail.com','2021-04-15 20:03:42'),(9,'ANTONIO','QUINTANA','8994',_binary '\0','4246','antonio2@gmail.com','2021-04-15 20:04:30'),(10,'CONSUMIDOR','FINAL','C/F',_binary '\0','0','0','2021-05-18 12:06:01'),(11,'CARLOS','ANDRADE','123',_binary '\0','4247','carlosand@email.com','2021-05-18 14:59:18'),(12,'FERNANDO','LUNA','3322',_binary '\0','4421','afernadoLn@email.com','2021-05-18 15:08:17'),(14,'CARLOS ANTONIO','HERRERA','432',_binary '\0','2222','antonio@email.com','2021-05-20 18:28:19'),(16,'MAURICIO','PEREZ SAS','444',_binary '\0','3312','maupersas@email.com','2021-05-25 14:58:06');
/*!40000 ALTER TABLE `clientes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `compras`
--

DROP TABLE IF EXISTS `compras`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compras` (
  `idcompra` int NOT NULL AUTO_INCREMENT,
  `no_orden_compra` int DEFAULT NULL,
  `idproveedor` int DEFAULT NULL,
  `fecha_orden` date DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idcompra`),
  KEY `idproveedor_proveedores_compras_idx` (`idproveedor`),
  CONSTRAINT `idproveedor_proveedores_compras` FOREIGN KEY (`idproveedor`) REFERENCES `proveedores` (`idproveedor`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `compras`
--

LOCK TABLES `compras` WRITE;
/*!40000 ALTER TABLE `compras` DISABLE KEYS */;
INSERT INTO `compras` VALUES (1,101,1,'2021-04-15','2021-04-15 19:15:19'),(2,102,1,'2021-04-15','2021-04-15 19:15:19'),(3,103,5,'2021-04-15','2021-04-15 19:15:19'),(4,104,3,'2021-04-15','2021-04-15 19:15:19'),(6,106,1,'2021-05-05','2021-05-26 17:37:14'),(7,107,5,'2020-09-09','2021-05-26 18:47:43');
/*!40000 ALTER TABLE `compras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `compras_detalle`
--

DROP TABLE IF EXISTS `compras_detalle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compras_detalle` (
  `idcompras_detalle` bigint NOT NULL AUTO_INCREMENT,
  `idcompra` int DEFAULT NULL,
  `idproducto` int DEFAULT NULL,
  `cantidad` int DEFAULT NULL,
  `precio_costo_unitario` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`idcompras_detalle`),
  KEY `idcompra_compras_comprasdetalle_idx` (`idcompra`),
  KEY `idproducto_productos_compras_detalle_idx` (`idproducto`),
  CONSTRAINT `idcompra_compras_compras_detalle` FOREIGN KEY (`idcompra`) REFERENCES `compras` (`idcompra`) ON UPDATE CASCADE,
  CONSTRAINT `idproducto_productos_compras_detalle` FOREIGN KEY (`idproducto`) REFERENCES `productos` (`idProducto`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `compras_detalle`
--

LOCK TABLES `compras_detalle` WRITE;
/*!40000 ALTER TABLE `compras_detalle` DISABLE KEYS */;
INSERT INTO `compras_detalle` VALUES (1,1,2,200,1000.00),(2,2,3,43,1000.00),(3,2,4,12,300.00),(4,3,5,20,900.00),(5,4,6,12,3000.00),(6,6,3,2,1000.00),(7,6,3,1,2000.00),(10,7,2,20,5000.00),(11,7,4,10,900.00);
/*!40000 ALTER TABLE `compras_detalle` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `empleados`
--

DROP TABLE IF EXISTS `empleados`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `empleados` (
  `idEmpleado` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `DPI` varchar(15) DEFAULT NULL,
  `genero` bit(1) DEFAULT NULL,
  `fecha_nacimento` date DEFAULT NULL,
  `idPuesto` smallint DEFAULT NULL,
  `fecha_inicio_labores` date DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idEmpleado`),
  KEY `id_puestos_empleados_idx` (`idPuesto`),
  CONSTRAINT `id_puestos_empleados` FOREIGN KEY (`idPuesto`) REFERENCES `puestos` (`id_puesto`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `empleados`
--

LOCK TABLES `empleados` WRITE;
/*!40000 ALTER TABLE `empleados` DISABLE KEYS */;
INSERT INTO `empleados` VALUES (1,'ANDRES','HERNANDEZ','ANTIGUA G','9090','6666',_binary '\0','2002-02-24',1,'2021-05-01','2021-04-15 19:47:51'),(2,'PAULINA','PEREZ','GUATEMALA','9091','7777',_binary '','1999-01-01',2,'2021-05-01','2021-04-15 19:47:52'),(3,'CARLA','CAMPOS','GUATEMALA','9092','8888',_binary '','1999-12-13',3,'2021-05-01','2021-04-15 19:47:52'),(4,'ANTONIO','PEREZ','ANTIGUA G','9093','9999',_binary '\0','1998-09-04',4,'2021-05-15','2021-04-15 19:47:52'),(6,'MARIA','GODOY','ANTIGUA','123','321',_binary '','2002-01-01',2,'2021-02-22','2021-05-14 00:58:36');
/*!40000 ALTER TABLE `empleados` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `marcas`
--

DROP TABLE IF EXISTS `marcas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `marcas` (
  `idmarca` smallint NOT NULL AUTO_INCREMENT,
  `marca` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`idmarca`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `marcas`
--

LOCK TABLES `marcas` WRITE;
/*!40000 ALTER TABLE `marcas` DISABLE KEYS */;
INSERT INTO `marcas` VALUES (1,'SAMSUNG'),(2,'CANON'),(3,'HP'),(4,'DELL'),(5,'LG');
/*!40000 ALTER TABLE `marcas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `productos`
--

DROP TABLE IF EXISTS `productos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `productos` (
  `idProducto` int NOT NULL AUTO_INCREMENT,
  `producto` varchar(50) DEFAULT NULL,
  `idMarca` smallint DEFAULT NULL,
  `descripcion` varchar(100) DEFAULT NULL,
  `imagen` varchar(30) DEFAULT NULL,
  `precio_costo` decimal(8,2) DEFAULT NULL,
  `precio_venta` decimal(8,2) DEFAULT NULL,
  `existencia` int DEFAULT NULL,
  `fecha_ingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idProducto`),
  KEY `idMarca_marcas_productos_idx` (`idMarca`),
  CONSTRAINT `idMarca_marcas_productos` FOREIGN KEY (`idMarca`) REFERENCES `marcas` (`idmarca`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `productos`
--

LOCK TABLES `productos` WRITE;
/*!40000 ALTER TABLE `productos` DISABLE KEYS */;
INSERT INTO `productos` VALUES (2,'TELEVISOR',1,'24 PULGADAS','tv.jpg',1000.00,2000.00,100,'2021-04-15 19:10:33'),(3,'LAPTOP',3,'MODELO INSPIRO 15385','laptop85.jpg',1000.00,6000.00,30,'2021-04-15 19:11:20'),(4,'IMPRESORA',2,'MODELO C123','Impc123.png',300.00,950.00,40,'2021-04-15 19:11:20'),(5,'ESTUFA',5,'4 HORNILLAS CON HORNO','estufa4.png',900.00,2300.00,50,'2021-04-15 19:11:20'),(6,'REFRIGERADOR',5,'DISPENSADOR HIELO','freezerd.img',2000.00,5000.00,99,'2021-04-15 19:11:20'),(8,'MOUSE',2,'GAMING','mouspad.png',100.00,150.00,60,'2021-05-26 11:22:02');
/*!40000 ALTER TABLE `productos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proveedores`
--

DROP TABLE IF EXISTS `proveedores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `proveedores` (
  `idproveedor` int NOT NULL AUTO_INCREMENT,
  `proveedor` varchar(60) DEFAULT NULL,
  `nit` varchar(12) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`idproveedor`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proveedores`
--

LOCK TABLES `proveedores` WRITE;
/*!40000 ALTER TABLE `proveedores` DISABLE KEYS */;
INSERT INTO `proveedores` VALUES (1,'CARLOS SANTANA','1111','ANTIGUA G','1234'),(2,'JOSE PAZ','2222','JOCOTENANGO','2345'),(3,'MARIO JUAREZ','3333','GUATEMALA','3456'),(4,'ARIANA SIS','4444','ANTIGUA G','4567'),(5,'MARIA FERNANDEZ','5555','GUATEMALA','3421'),(7,'JUAN PEDRO','9091','GUATEMALA','1001'),(8,'MARIA SOFIA','9092','JOCOTENANGO','2001');
/*!40000 ALTER TABLE `proveedores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `puestos`
--

DROP TABLE IF EXISTS `puestos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `puestos` (
  `id_puesto` smallint NOT NULL AUTO_INCREMENT,
  `puesto` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id_puesto`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `puestos`
--

LOCK TABLES `puestos` WRITE;
/*!40000 ALTER TABLE `puestos` DISABLE KEYS */;
INSERT INTO `puestos` VALUES (1,'GERENTE'),(2,'ASESOR'),(3,'CONTADOR'),(4,'CAJERO'),(5,'PROGRAMADOR');
/*!40000 ALTER TABLE `puestos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ventas`
--

DROP TABLE IF EXISTS `ventas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ventas` (
  `idVenta` int NOT NULL AUTO_INCREMENT,
  `nofactura` int DEFAULT NULL,
  `serie` char(1) DEFAULT NULL,
  `fechafactura` date DEFAULT NULL,
  `idCliente` int DEFAULT NULL,
  `idEmpleado` int DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idVenta`),
  KEY `id_clientes_empleados_idx` (`idCliente`),
  KEY `id_empleados_ventas_idx` (`idEmpleado`),
  CONSTRAINT `id_clientes_ventas` FOREIGN KEY (`idCliente`) REFERENCES `clientes` (`idCliente`) ON UPDATE CASCADE,
  CONSTRAINT `id_empleados_ventas` FOREIGN KEY (`idEmpleado`) REFERENCES `empleados` (`idEmpleado`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ventas`
--

LOCK TABLES `ventas` WRITE;
/*!40000 ALTER TABLE `ventas` DISABLE KEYS */;
INSERT INTO `ventas` VALUES (1,100,'A','2021-04-15',5,2,'2021-04-15 20:08:31'),(2,101,'A','2021-04-15',6,2,'2021-04-15 20:09:21'),(4,103,'A','2021-04-15',8,2,'2021-04-15 20:10:00'),(5,100,'B','2021-04-16',11,4,'2021-04-15 20:10:19'),(6,101,'B','2021-04-15',9,4,'2021-04-15 20:10:30'),(8,101,'C','2021-05-17',11,6,'2021-05-17 23:46:05'),(10,102,'C','2021-05-23',6,4,'2021-05-20 15:33:03'),(11,100,'C','2021-05-20',11,1,'2021-05-20 17:26:56'),(12,103,'C','2021-05-20',10,2,'2021-05-20 17:32:46'),(14,100,'D','2021-05-20',14,1,'2021-05-20 18:28:40'),(15,101,'D','2021-05-22',10,2,'2021-05-22 13:38:25'),(16,102,'D','2021-05-25',11,2,'2021-05-25 14:56:47'),(18,103,'D','2021-05-25',10,3,'2021-05-25 15:06:12');
/*!40000 ALTER TABLE `ventas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ventas_detalle`
--

DROP TABLE IF EXISTS `ventas_detalle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ventas_detalle` (
  `idventas_detalle` bigint NOT NULL AUTO_INCREMENT,
  `idVenta` int DEFAULT NULL,
  `idProducto` int DEFAULT NULL,
  `cantidad` varchar(45) DEFAULT NULL,
  `precio_unitario` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`idventas_detalle`),
  KEY `id_ventas_ventas_detalle_idx` (`idVenta`),
  KEY `id_producto_ventas_detalle_idx` (`idProducto`),
  CONSTRAINT `id_producto_ventas_detalle` FOREIGN KEY (`idProducto`) REFERENCES `productos` (`idProducto`) ON UPDATE CASCADE,
  CONSTRAINT `id_ventas_ventas_detalle` FOREIGN KEY (`idVenta`) REFERENCES `ventas` (`idVenta`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ventas_detalle`
--

LOCK TABLES `ventas_detalle` WRITE;
/*!40000 ALTER TABLE `ventas_detalle` DISABLE KEYS */;
INSERT INTO `ventas_detalle` VALUES (6,1,2,'3',2000.00),(7,2,2,'2',2000.00),(9,4,3,'1',6000.00),(10,5,5,'2',2300.00),(11,8,2,'2',2000.00),(12,8,3,'1',6000.00),(14,10,2,'2',2000.00),(16,6,2,'2',2000.00),(17,11,3,'2',6000.00),(18,11,2,'3',2000.00),(19,12,4,'2',950.00),(20,12,2,'4',2000.00),(21,14,2,'3',2000.00),(22,14,3,'4',6000.00),(23,15,2,'4',2000.00),(25,10,4,'1',950.00),(26,10,3,'2',6000.00),(28,18,3,'4',6000.00),(29,18,2,'2',2000.00);
/*!40000 ALTER TABLE `ventas_detalle` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-05-26 20:05:34
