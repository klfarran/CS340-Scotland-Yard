
	#include <iostream>

	#include "GameManager.h"
	#include "Station.h"
	#include "Edge.h"
	
	using namespace std;


	//contructor	
	GameManager::GameManager(){
		//game has to start on round 0, can't start game in middle of rounds
		round = 0; 
	}

	//function to return the number of the current round of the game 
	int GameManager::getRound(){
		return round;
	}
	
	//function to initialize the game board 
	//to be implemented
	vector<Station> GameManager::initializeBoard() {
		
	   vector<Station> board; 
		
		//edge definitions 
		Edge edge1  (1, 8, TAXI);
		Edge edge2  (1, 9, TAXI)  ;
		Edge edge3  (1, 46, BUS | UNDERGROUND);
		Edge edge4  (1, 58, BUS);
		Edge edge5  (2, 10, TAXI );
		Edge edge6  (2, 20, TAXI  );
		Edge edge7  (3, 4, TAXI  );
		Edge edge8  (3, 11, TAXI  );
		Edge edge9  (3, 12, TAXI  );
		Edge edge10 (3, 22, BUS);
		Edge edge11 (3, 23, BUS);
		Edge edge12 (4, 3, TAXI  );
		Edge edge13 (4, 13, TAXI  );
		Edge edge14 (5, 15, TAXI );
		Edge edge15 (5, 16, TAXI  );
		Edge edge16 (6, 7, TAXI  );
		Edge edge17 (6, 29, TAXI  );
		Edge edge18 (7, 6, TAXI  );
		Edge edge19 (7, 17, TAXI  );
		Edge edge20 (7, 42, BUS);
		Edge edge21 (8, 1, TAXI  );
		Edge edge22 (8, 18, TAXI  );
		Edge edge23 (8, 19, TAXI  );
		Edge edge24 (9, 1, TAXI  );
		Edge edge25 (9, 19, TAXI  );
		Edge edge26 (9, 20, TAXI  );
		Edge edge27 (10, 2, TAXI  );
		Edge edge28 (10, 11, TAXI  );
		Edge edge29 (10, 21, TAXI  );
		Edge edge30 (10, 34, TAXI  );
		Edge edge31 (11, 3, TAXI );
		Edge edge32 (11, 10, TAXI  );
		Edge edge33 (11, 22, TAXI  );
		Edge edge34 (12, 3, TAXI  );
		Edge edge35 (12, 23, TAXI  );
		Edge edge36 (13, 4, TAXI  );
		Edge edge37 (13, 14, TAXI | BUS);
		Edge edge38 (13, 23, TAXI | BUS);
		Edge edge39 (13, 24, TAXI  );
		Edge edge40 (13, 52, BUS);
		Edge edge41 (13, 46, UNDERGROUND);
		Edge edge42 (13, 67, UNDERGROUND);
		Edge edge43 (13, 89, UNDERGROUND);
		Edge edge44 (14, 13, TAXI | BUS);
		Edge edge45 (14, 15, TAXI | BUS);
		Edge edge46 (14, 25, TAXI | );
		Edge edge47 (15, 5, TAXI  );
		Edge edge48 (15, 14, TAXI | BUS);
		Edge edge49 (15, 16, TAXI  );
		Edge edge50 (15, 26, TAXI | );
		Edge edge51 (15, 28, TAXI | );
		Edge edge52 (15, 29, BUS);
		Edge edge53 (15, 41, BUS);
		Edge edge54 (16, 5, TAXI | );
		Edge edge55 (16, 15, TAXI | );
		Edge edge56 (16, 28, TAXI | );
		Edge edge57 (16, 29, TAXI | );
		Edge edge58 (17, 7, TAXI | );
		Edge edge59 (17, 29, TAXI | );
		Edge edge60 (17, 30, TAXI | );
		Edge edge61 (18, 8, TAXI | );
		Edge edge62 (18, 31, TAXI | );
		Edge edge63 (18, 43, TAXI | );
		Edge edge64 (19, 8, TAXI | );
		Edge edge65 (19, 9, TAXI | );
		Edge edge66 (19, 32, TAXI | );
		Edge edge67 (20, 2, TAXI | );
		Edge edge68 (20, 9, TAXI | );
		Edge edge69 (20, 33, TAXI | );
		Edge edge70 (21, 10, TAXI | );
		Edge edge71 (21, 33, TAXI | );
		Edge edge72 (22, 11, TAXI | );
		Edge edge73 (22, 23, TAXI | BUS);
		Edge edge74 (22, 34, TAXI | BUS);
		Edge edge75 (22, 35, TAXI | );
		Edge edge76 (22, 65, BUS);
		Edge edge77 (23, 12, TAXI | );
		Edge edge78 (23, 13, TAXI | BUS);
		Edge edge79 (23, 22, TAXI | BUS);
		Edge edge80 (23, 37, TAXI | );
		Edge edge81 (23, 67, BUS);
		Edge edge82 (24, 13, TAXI | );
		Edge edge83 (24, 37, TAXI | );
		Edge edge84 (24, 38, TAXI | );
		Edge edge85 (25, 14, TAXI | );
		Edge edge86 (25, 38, TAXI | );
		Edge edge87 (25, 39, TAXI | );
		Edge edge88 (26, 15, TAXI | );
		Edge edge89 (26, 27, TAXI | );
		Edge edge90 (26, 39, TAXI | );
		Edge edge91 (27, 26, TAXI | );
		Edge edge92 (27, 28, TAXI | );
		Edge edge93 (27, 40, TAXI | );
		Edge edge94 (28, 15, TAXI | );
		Edge edge95 (28, 16, TAXI | );
		Edge edge96 (28, 27, TAXI | );
		Edge edge97 (28, 41, TAXI | );
		Edge edge98 (29, 6, TAXI | );
		Edge edge99 (29, 16, TAXI | );
		Edge edge100(29, 17, TAXI | );
		Edge edge101(29, 41, TAXI | BUS);
		Edge edge102(29, 42, TAXI | BUS);
		Edge edge103(29, 15, BUS);
		Edge edge104(29, 55, BUS);
		Edge edge105(30, 17, TAXI | );
		Edge edge106(30, 42, BUS);
		Edge edge107(31, 18, TAXI | );
		Edge edge108(31, 43, TAXI | );
		Edge edge109(31, 44, TAXI | );
		Edge edge110(32, 19, TAXI | );
		Edge edge111(32, 33, TAXI | );
		Edge edge112(32, 44, TAXI | );
		Edge edge113(32, 45, TAXI | );
		Edge edge114(33, 20, TAXI | );
		Edge edge115(33, 21, TAXI | );
		Edge edge116(33, 32, TAXI | );
		Edge edge117(33, 46, TAXI | );
		Edge edge118(34, 10, TAXI | );
		Edge edge119(34, 22, TAXI | BUS);
		Edge edge120(34, 47, TAXI | );
		Edge edge121(34, 48, TAXI | );
		Edge edge122(34, 46, BUS);
		Edge edge123(34, 63, BUS);
		Edge edge124(35, 22, TAXI | );
		Edge edge125(35, 36, TAXI | );
		Edge edge126(35, 48, TAXI | );
		Edge edge127(35, 65, TAXI | );
		Edge edge128(36, 35, TAXI | );
		Edge edge129(36, 37, TAXI | );
		Edge edge130(36, 49, TAXI | );
		Edge edge131(37, 23, TAXI | );
		Edge edge132(37, 24, TAXI | );
		Edge edge133(37, 36, TAXI | );
		Edge edge134(37, 50, TAXI | );
		Edge edge135(38, 24, TAXI | );
		Edge edge136(38, 25, TAXI | );
		Edge edge137(38, 50, TAXI | );
		Edge edge138(38, 51, TAXI | );
		Edge edge139(39, 25, TAXI | );
		Edge edge140(39, 26, TAXI | );
		Edge edge141(39, 51, TAXI | );
		Edge edge142(39, 52, TAXI | );
		Edge edge143(40, 27, TAXI | );
		Edge edge144(40, 41, TAXI | );
		Edge edge145(40, 52, TAXI | );
		Edge edge146(40, 53, TAXI | );
		Edge edge147(41, 28, TAXI | );
		Edge edge148(41, 29, TAXI | BUS);
		Edge edge149(41, 40, TAXI | );
		Edge edge150(41, 54, TAXI | );
		Edge edge151(41, 15, BUS);
		Edge edge152(41, 52, BUS);
		Edge edge153(41, 87, BUS);
		Edge edge154(42, 29, TAXI | BUS);
		Edge edge155(42, 30, TAXI | );
		Edge edge156(42, 56, TAXI | );
		Edge edge157(42, 72, TAXI | BUS);
		Edge edge158(42, 7, BUS);
		Edge edge159(43, 18, TAXI | );
		Edge edge160(43, 31, TAXI | );
		Edge edge161(43, 57, TAXI | );
		Edge edge162(44, 31, TAXI | );
		Edge edge163(44, 32, TAXI | );
		Edge edge164(44, 58, TAXI | );
		Edge edge165(45, 32, TAXI | );
		Edge edge166(45, 46, TAXI | );
		Edge edge167(45, 58, TAXI | );
		Edge edge168(45, 59, TAXI | );
		Edge edge169(45, 60, TAXI | );
		Edge edge170(46, 33, TAXI | );
		Edge edge171(46, 45, TAXI | );
		Edge edge172(46, 47, TAXI | );
		Edge edge173(46, 61, TAXI | );
		Edge edge174(46, 1, BUS | UNDERGROUND);
		Edge edge175(46, 34, BUS);
		Edge edge176(46, 58, BUS);
		Edge edge177(46, 78, BUS);
		Edge edge178(46, 13, UNDERGROUND);
		Edge edge179(46, 74, UNDERGROUND);
		Edge edge180(46, 79, UNDERGROUND);
		Edge edge181(47, 34, TAXI | );
		Edge edge182(47, 46, TAXI | );
		Edge edge183(47, 62, TAXI | );
		Edge edge184(48, 34, TAXI | );
		Edge edge185(48, 35, TAXI | );
		Edge edge186(48, 62, TAXI | );
		Edge edge187(48, 63, TAXI | );
		Edge edge188(49, 36, TAXI | );
		Edge edge189(49, 50, TAXI | );
		Edge edge190(49, 66, TAXI | );
		Edge edge191(50, 37, TAXI | );
		Edge edge192(50, 38, TAXI | );
		Edge edge193(50, 49, TAXI | );
		Edge edge194(51, 38, TAXI | );
		Edge edge195(51, 39, TAXI | );
		Edge edge196(51, 52, TAXI | );
		Edge edge197(51, 67, TAXI | );
		Edge edge198(51, 68, TAXI | );
		Edge edge199(52, 39, TAXI | );
		Edge edge200(52, 40, TAXI | );
		Edge edge201(52, 51, TAXI | );
		Edge edge202(52, 69, TAXI | );
		Edge edge203(52, 13, BUS);
		Edge edge204(52, 41, BUS);
		Edge edge205(52, 67, BUS);
		Edge edge206(52, 86, BUS);
		Edge edge207(53, 40, TAXI | );
		Edge edge208(53, 54, TAXI | );
		Edge edge209(53, 69, TAXI | );
		Edge edge210(54, 41, TAXI | );
		Edge edge211(54, 53, TAXI | );
		Edge edge212(54, 55, TAXI | );
		Edge edge213(54, 70, TAXI | );
		Edge edge214(55, 54, TAXI | );
		Edge edge215(55, 71, TAXI | );
		Edge edge216(55, 29, BUS);
		Edge edge217(55, 89, BUS);
		Edge edge218(56, 42, TAXI | );
		Edge edge219(56, 91, TAXI | );
		Edge edge220(57, 43, TAXI | );
		Edge edge221(57, 59, TAXI | );
		Edge edge222(57, 73, TAXI | );
		Edge edge223(58, 44, TAXI | );
		Edge edge224(58, 45, TAXI | );
		Edge edge225(58, 57, TAXI | );
		Edge edge226(58, 59, TAXI | );
		Edge edge227(58, 74, TAXI | );
		Edge edge228(58, 75, TAXI | );
		Edge edge229(58, 1, BUS);
		Edge edge230(58, 46, BUS);
		Edge edge231(58, 74, BUS);
		Edge edge232(58, 77, BUS);
		Edge edge233(59, 45, TAXI | );
		Edge edge234(59, 58, TAXI | );
		Edge edge235(59, 75, TAXI | );
		Edge edge236(59, 76, TAXI | );
		Edge edge237(60, 45, TAXI | );
		Edge edge238(60, 61, TAXI | );
		Edge edge239(60, 76, TAXI | );
		Edge edge240(61, 46, TAXI | );
		Edge edge241(61, 60, TAXI | );
		Edge edge242(61, 62, TAXI | );
		Edge edge243(61, 76, TAXI | );
		Edge edge244(61, 78, TAXI | );
		Edge edge245(62, 47, TAXI | );
		Edge edge246(62, 48, TAXI | );
		Edge edge247(62, 61, TAXI | );
		Edge edge248(62, 79, TAXI | );
		Edge edge249(63, 48, TAXI | );
		Edge edge250(63, 64, TAXI | );
		Edge edge251(63, 79, TAXI | BUS);
		Edge edge252(63, 80, TAXI | );
		Edge edge253(63, 34, BUS);
		Edge edge254(63, 65, BUS);
		Edge edge255(63, 100, BUS);
		Edge edge256(64, 63, TAXI | );
		Edge edge257(64, 65, TAXI | );
		Edge edge258(64, 81, TAXI | );
		Edge edge259(65, 66, TAXI | );
		Edge edge260(65, 82, TAXI | );
		Edge edge261(65, 22, BUS);
		Edge edge262(65, 63, BUS);
		Edge edge263(65, 67, BUS);
		Edge edge264(65, 82, BUS);
		Edge edge265(66, 49, TAXI | );
		Edge edge266(66, 65, TAXI | );
		Edge edge267(66, 67, TAXI | );
		Edge edge268(66, 82, TAXI | );
		Edge edge269(67, 51, TAXI | );
		Edge edge270(67, 66, TAXI | );
		Edge edge271(67, 68, TAXI | );
		Edge edge272(67, 84, TAXI | );
		Edge edge273(67, 23, BUS);
		Edge edge274(67, 52, BUS);
		Edge edge275(67, 65, BUS);
		Edge edge276(67, 82, BUS);
		Edge edge277(67, 102, BUS);
		Edge edge278(67, 13, UNDERGROUND);
		Edge edge279(67, 79, UNDERGROUND);
		Edge edge280(67, 89, UNDERGROUND);
		Edge edge281(67, 111, UNDERGROUND);
		Edge edge282(68, 51, TAXI | );
		Edge edge283(68, 67, TAXI | );
		Edge edge284(68, 69, TAXI | );
		Edge edge285(68, 85, TAXI | );
		Edge edge286(69, 52, TAXI | );
		Edge edge287(69, 53, TAXI | );
		Edge edge288(69, 68, TAXI | );
		Edge edge289(69, 86, TAXI | );
		Edge edge290(70, 54, TAXI | );
		Edge edge291(70, 71, TAXI | );
		Edge edge292(70, 87, TAXI | );
		Edge edge293(71, 55, TAXI | );
		Edge edge294(71, 70, TAXI | );
		Edge edge295(71, 72, TAXI | );
		Edge edge296(71, 89, TAXI | );
		Edge edge297(72, 42, TAXI | BUS);
		Edge edge298(72, 71, TAXI | );
		Edge edge299(72, 90, TAXI | );
		Edge edge300(72, 91, TAXI | );
		Edge edge301(72, 105, BUS);
		Edge edge302(72, 107, BUS);
		Edge edge303(73, 57, TAXI | );
		Edge edge304(73, 74, BUS);
		Edge edge305(73, 92, TAXI | );
		Edge edge306(74, 58, TAXI | BUS);
		Edge edge307(74, 73, TAXI | );
		Edge edge308(74, 75, TAXI | );
		Edge edge309(74, 92, TAXI | );
		Edge edge310(74, 94, BUS);
		Edge edge311(75, 58, TAXI | );
		Edge edge312(75, 59, TAXI | );
		Edge edge313(75, 74, TAXI | );
		Edge edge314(75, 94, TAXI | );
		Edge edge315(76, 59, TAXI | );
		Edge edge316(76, 60, TAXI | );
		Edge edge317(76, 61, TAXI | );
		Edge edge318(76, 77, TAXI | );
		Edge edge319(77, 76, TAXI | );
		Edge edge320(77, 78, TAXI | BUS);
		Edge edge321(77, 95, TAXI | );
		Edge edge322(77, 96, TAXI | );
		Edge edge323(77, 58, BUS);
		Edge edge324(77, 94, BUS);
		Edge edge325(77, 124, BUS);
		Edge edge326(78, 61, TAXI | );
		Edge edge327(78, 77, TAXI | BUS);
		Edge edge328(78, 79, TAXI | BUS);
		Edge edge329(78, 97, TAXI | );
		Edge edge330(79, 62, TAXI | );
		Edge edge331(79, 63, TAXI | BUS);
		Edge edge332(79, 78, TAXI | BUS);
		Edge edge333(79, 98, TAXI | );
		Edge edge334(79, 46, UNDERGROUND);
		Edge edge335(79, 67, UNDERGROUND);
		Edge edge336(79, 93, UNDERGROUND);
		Edge edge337(79, 111, UNDERGROUND);
		Edge edge338(80, 63, TAXI | );
		Edge edge339(80, 99, TAXI | );
		Edge edge340(80, 100, TAXI | );
		Edge edge341(81, 64, TAXI | );
		Edge edge342(81, 82, TAXI | );
		Edge edge343(81, 82, TAXI | );
		Edge edge344(81, 100, TAXI | );
		Edge edge345(82, 65, TAXI | BUS);
		Edge edge346(82, 66, TAXI | );
		Edge edge347(82, 81, TAXI | );
		Edge edge348(82, 101, TAXI | );
		Edge edge349(82, 67, BUS);
		Edge edge350(82, 100, BUS);
		Edge edge351(82, 140, BUS);
		Edge edge352(83, 101, TAXI | );
		Edge edge353(83, 102, TAXI | );
		Edge edge354(84, 67, TAXI | );
		Edge edge355(84, 85, TAXI | );
		Edge edge356(85, 68, TAXI | );
		Edge edge357(85, 84, TAXI | );
		Edge edge358(85, 103, TAXI | );
		Edge edge359(86, 69, TAXI | );
		Edge edge360(86, 103, TAXI | );
		Edge edge361(86, 104, TAXI | );
		Edge edge362(86, 52, BUS);
		Edge edge363(86, 87, BUS);
		Edge edge364(86, 102, BUS);
		Edge edge365(86, 116, BUS);
		Edge edge366(87, 70, TAXI | );
		Edge edge367(87, 88, TAXI | );
		Edge edge368(87, 41, BUS);
		Edge edge369(87, 86, BUS);
		Edge edge370(87, 105, BUS);
		Edge edge371(88, 87, TAXI | );
		Edge edge372(88, 89, TAXI | );
		Edge edge373(88, 117, TAXI | );
		Edge edge374(89, 71, TAXI | );
		Edge edge375(89, 88, TAXI | );
		Edge edge376(89, 105, TAXI | BUS);
		Edge edge377(89, 55, BUS);
		Edge edge378(89, 13, UNDERGROUND);
		Edge edge379(89, 67, UNDERGROUND);
		Edge edge380(89, 128, UNDERGROUND);
		Edge edge381(89, 140, UNDERGROUND);
		Edge edge382(90, 72, TAXI | );
		Edge edge383(90, 91, TAXI | );
		Edge edge384(90, 105, TAXI | );
		Edge edge385(91, 56, TAXI | );
		Edge edge386(91, 72, TAXI | );
		Edge edge387(91, 90, TAXI | );
		Edge edge388(91, 105, TAXI | );
		Edge edge389(91, 107, TAXI | );
		Edge edge390(92, 73, TAXI | );
		Edge edge391(92, 74, TAXI | );
		Edge edge392(92, 93, TAXI | );
		Edge edge393(93, 92, TAXI | );
		Edge edge394(93, 94, TAXI | BUS);
		Edge edge395(93, 79, UNDERGROUND);
		Edge edge396(94, 75, TAXI | );
		Edge edge397(94, 93, TAXI | BUS);
		Edge edge398(94, 95, TAXI | );
		Edge edge399(94, 74, BUS);
		Edge edge400(94, 77, BUS);
		Edge edge401(95, 77, TAXI | );
		Edge edge402(95, 94, TAXI | );
		Edge edge403(95, 122, TAXI | );
		Edge edge404(96, 77, TAXI | );
		Edge edge405(96, 97, TAXI | );
		Edge edge406(96, 109, TAXI | );
		Edge edge407(97, 78, TAXI | );
		Edge edge408(97, 96, TAXI | );
		Edge edge409(97, 98, TAXI | );
		Edge edge410(97, 109, TAXI | );
		Edge edge411(98, 79, TAXI | );
		Edge edge412(98, 97, TAXI | );
		Edge edge413(98, 99, TAXI | );
		Edge edge414(98, 110, TAXI | );
		Edge edge415(99, 80, TAXI | );
		Edge edge416(99, 98, TAXI | );
		Edge edge417(99, 110, TAXI | );
		Edge edge418(99, 112, TAXI | );
		Edge edge419(100, 80, TAXI | );
		Edge edge420(100, 81, TAXI | );
		Edge edge421(100, 101, TAXI | );
		Edge edge422(100, 112, TAXI | );
		Edge edge423(100, 113, TAXI | );
		Edge edge424(100, 63, BUS);
		Edge edge425(100, 82, BUS);
		Edge edge426(100, 111, BUS);
		Edge edge427(101, 82, TAXI | );
		Edge edge428(101, 82, TAXI | );
		Edge edge429(101, 100, TAXI | );
		Edge edge430(101, 114, TAXI | );
		Edge edge431(102, 83, TAXI | );
		Edge edge432(102, 103, TAXI | );
		Edge edge433(102, 115, TAXI | );
		Edge edge434(103, 85, TAXI | );
		Edge edge435(103, 86, TAXI | );
		Edge edge436(103, 102, TAXI | );
		Edge edge437(104, 86, TAXI | );
		Edge edge438(104, 116, TAXI | );
		Edge edge439(105, 89, TAXI | BUS);
		Edge edge440(105, 90, TAXI | );
		Edge edge441(105, 91, TAXI | );
		Edge edge442(105, 106, TAXI | );
		Edge edge443(105, 108, TAXI | BUS);
		Edge edge444(105, 72, BUS);
		Edge edge445(105, 87, BUS);
		Edge edge446(105, 107, BUS);
		Edge edge447(106, 105, TAXI | );
		Edge edge448(106, 107, TAXI | );
		Edge edge449(107, 91, TAXI | );
		Edge edge450(107, 106, TAXI | );
		Edge edge451(107, 119, TAXI | );
		Edge edge452(107, 72, BUS);
		Edge edge453(107, 105, BUS);
		Edge edge454(107, 161, BUS);
		Edge edge455(108, 105, TAXI | BUS);
		Edge edge456(108, 117, TAXI | );
		Edge edge457(108, 119, TAXI | );
		Edge edge458(108, 116, BUS);
		Edge edge459(108, 135, BUS);
		Edge edge460(108, 115, L);
		Edge edge461(109, 96, TAXI | );
		Edge edge462(109, 97, TAXI | );
		Edge edge463(109, 110, TAXI | );
		Edge edge464(109, 124, TAXI | );
		Edge edge465(110, 98, TAXI | );
		Edge edge466(110, 99, TAXI | );
		Edge edge467(110, 109, TAXI | );
		Edge edge468(110, 111, TAXI | );
		Edge edge469(111, 110, TAXI | );
		Edge edge470(111, 112, TAXI | );
		Edge edge471(111, 124, TAXI | BUS);
		Edge edge472(111, 100, BUS);
		Edge edge473(111, 67, UNDERGROUND);
		Edge edge474(111, 79, UNDERGROUND);
		Edge edge475(111, 153, UNDERGROUND);
		Edge edge476(111, 163, UNDERGROUND);
		Edge edge477(112, 99, TAXI | );
		Edge edge478(112, 100, TAXI | );
		Edge edge479(112, 111, TAXI | );
		Edge edge480(112, 125, TAXI | );
		Edge edge481(113, 100, TAXI | );
		Edge edge482(113, 114, TAXI | );
		Edge edge483(113, 125, TAXI | );
		Edge edge484(114, 101, TAXI | );
		Edge edge485(114, 113, TAXI | );
		Edge edge486(114, 115, TAXI | );
		Edge edge487(114, 126, TAXI | );
		Edge edge488(114, 131, TAXI | );
		Edge edge489(114, 132, TAXI | );
		Edge edge490(115, 102, TAXI | );
		Edge edge491(115, 114, TAXI | );
		Edge edge492(115, 126, TAXI | );
		Edge edge493(115, 127, TAXI | );
		Edge edge494(115, 108, RIVER);
		Edge edge495(115, 157, RIVER);
		Edge edge496(116, 104, TAXI | );
		Edge edge497(116, 117, TAXI | );
		Edge edge498(116, 118, TAXI | );
		Edge edge499(116, 127, TAXI | );
		Edge edge500(116, 86, BUS);
		Edge edge501(116, 86, BUS);
		Edge edge502(116, 108, BUS);
		Edge edge503(116, 127, BUS);
		Edge edge504(116, 142, BUS);
		Edge edge505(117, 88, TAXI | );
		Edge edge506(117, 108, TAXI | );
		Edge edge507(117, 116, TAXI | );
		Edge edge508(117, 129, TAXI | );
		Edge edge509(118, 116, TAXI | );
		Edge edge510(118, 116, TAXI | );
		Edge edge511(118, 129, TAXI | );
		Edge edge512(118, 134, TAXI | );
		Edge edge513(118, 142, TAXI | );
		Edge edge514(119, 107, TAXI | );
		Edge edge515(119, 108, TAXI | );
		Edge edge516(119, 136, TAXI | );
		Edge edge517(120, 121, TAXI | );
		Edge edge518(120, 144, TAXI | );
		Edge edge519(121, 120, TAXI | );
		Edge edge520(121, 122, TAXI | );
		Edge edge521(121, 144, TAXI | );
		Edge edge522(122, 95, TAXI | );
		Edge edge523(122, 121, TAXI | );
		Edge edge524(122, 123, TAXI | BUS);
		Edge edge525(122, 146, TAXI | );
		Edge edge526(122, 144, BUS);
		Edge edge527(123, 122, TAXI | BUS);
		Edge edge528(123, 124, TAXI | BUS);
		Edge edge529(123, 137, TAXI | );
		Edge edge530(123, 148, TAXI | );
		Edge edge531(123, 149, TAXI | );
		Edge edge532(123, 144, BUS);
		Edge edge533(123, 165, BUS);
		Edge edge534(124, 109, TAXI | );
		Edge edge535(124, 111, TAXI | BUS);
		Edge edge536(124, 123, TAXI | BUS);
		Edge edge537(124, 130, TAXI | );
		Edge edge538(124, 138, TAXI | );
		Edge edge539(124, 77, BUS);
		Edge edge540(124, 153, BUS);
		Edge edge541(125, 112, TAXI | );
		Edge edge542(125, 113, TAXI | );
		Edge edge543(125, 131, TAXI | );
		Edge edge544(126, 114, TAXI | );
		Edge edge545(126, 115, TAXI | );
		Edge edge546(126, 127, TAXI | );
		Edge edge547(126, 140, TAXI | );
		Edge edge548(127, 115, TAXI | );
		Edge edge549(127, 116, TAXI | BUS);
		Edge edge550(127, 126, TAXI | );
		Edge edge551(127, 133, TAXI | BUS);
		Edge edge552(127, 134, TAXI | );
		Edge edge553(127, 102, BUS);
		Edge edge554(128, 142, TAXI | );
		Edge edge555(128, 143, TAXI | );
		Edge edge556(128, 160, TAXI | );
		Edge edge557(128, 172, TAXI | );
		Edge edge558(128, 188, TAXI | );
		Edge edge559(128, 135, BUS);
		Edge edge560(128, 142, BUS);
		Edge edge561(128, 161, BUS);
		Edge edge562(128, 187, BUS);
		Edge edge563(128, 199, BUS);
		Edge edge564(128, 89, UNDERGROUND);
		Edge edge565(128, 140, UNDERGROUND);
		Edge edge566(128, 185, UNDERGROUND);
		Edge edge567(129, 117, TAXI | );
		Edge edge568(129, 118, TAXI | );
		Edge edge569(129, 135, TAXI | );
		Edge edge570(129, 142, TAXI | );
		Edge edge571(129, 143, TAXI | );
		Edge edge572(130, 124, TAXI | );
		Edge edge573(130, 131, TAXI | );
		Edge edge574(130, 139, TAXI | );
		Edge edge575(131, 114, TAXI | );
		Edge edge576(131, 125, TAXI | );
		Edge edge577(131, 130, TAXI | );
		Edge edge578(132, 114, TAXI | );
		Edge edge579(132, 140, TAXI | );
		Edge edge580(133, 127, TAXI | BUS);
		Edge edge581(133, 140, TAXI | BUS);
		Edge edge582(133, 141, TAXI | );
		Edge edge583(133, 157, BUS);
		Edge edge584(134, 118, TAXI | );
		Edge edge585(134, 127, TAXI | );
		Edge edge586(134, 141, TAXI | );
		Edge edge587(134, 142, TAXI | );
		Edge edge588(135, 129, TAXI | );
		Edge edge589(135, 136, TAXI | );
		Edge edge590(135, 143, TAXI | );
		Edge edge591(135, 161, TAXI | BUS);
		Edge edge592(135, 108, BUS);
		Edge edge593(135, 128, BUS);
		Edge edge594(136, 119, TAXI | );
		Edge edge595(136, 135, TAXI | );
		Edge edge596(136, 162, TAXI | );
		Edge edge597(137, 123, TAXI | );
		Edge edge598(137, 147, TAXI | );
		Edge edge599(138, 124, TAXI | );
		Edge edge600(138, 150, TAXI | );
		Edge edge601(138, 152, TAXI | );
		Edge edge602(139, 130, TAXI | );
		Edge edge603(139, 140, TAXI | );
		Edge edge604(139, 153, TAXI | );
		Edge edge605(139, 154, TAXI | );
		Edge edge606(140, 126, TAXI | );
		Edge edge607(140, 132, TAXI | );
		Edge edge608(140, 133, TAXI | BUS);
		Edge edge609(140, 139, TAXI | );
		Edge edge610(140, 154, TAXI | BUS);
		Edge edge611(140, 156, TAXI | );
		Edge edge612(140, 82, BUS);
		Edge edge613(140, 89, UNDERGROUND);
		Edge edge614(140, 128, UNDERGROUND);
		Edge edge615(140, 153, UNDERGROUND);
		Edge edge616(141, 133, TAXI | );
		Edge edge617(141, 134, TAXI | );
		Edge edge618(141, 142, TAXI | );
		Edge edge619(142, 143, TAXI | );
		Edge edge620(142, 158, TAXI | );
		Edge edge621(142, 116, BUS);
		Edge edge622(142, 128, BUS);
		Edge edge623(142, 157, BUS);
		Edge edge624(143, 128, TAXI | );
		Edge edge625(143, 129, TAXI | );
		Edge edge626(143, 135, TAXI | );
		Edge edge627(143, 142, TAXI | );
		Edge edge628(143, 160, TAXI | );
		Edge edge629(144, 120, TAXI | );
		Edge edge630(144, 145, TAXI | );
		Edge edge631(144, 177, TAXI | );
		Edge edge632(144, 122, BUS);
		Edge edge633(144, 123, BUS);
		Edge edge634(144, 163, BUS);
		//Edge edge635(145, 121, TAXI | ); this is a repeated edge...same as edge638
		Edge edge636(144, 145, TAXI | );
		Edge edge637(144, 177, TAXI | );
		Edge edge638(145, 121, TAXI | );
		Edge edge639(145, 144, TAXI | );
		Edge edge640(145, 146, TAXI | );
		Edge edge641(146, 122, TAXI | );
		Edge edge642(146, 145, TAXI | );
		Edge edge643(146, 163, TAXI | );
		Edge edge644(147, 137, TAXI | );
		Edge edge645(147, 164, TAXI | );
		Edge edge646(148, 123, TAXI | );
		Edge edge647(148, 149, TAXI | );
		Edge edge648(148, 164, TAXI | );
		Edge edge649(149, 123, TAXI | );
		Edge edge650(149, 148, TAXI | );
		Edge edge651(149, 150, TAXI | );
		Edge edge652(149, 165, TAXI | );
		Edge edge653(150, 138, TAXI | );
		Edge edge654(150, 149, TAXI | );
		Edge edge655(150, 151, TAXI | );
		Edge edge656(151, 150, TAXI | );
		Edge edge657(151, 152, TAXI | );
		Edge edge658(151, 165, TAXI | );
		Edge edge659(151, 166, TAXI | );
		Edge edge660(152, 138, TAXI | );
		Edge edge661(152, 151, TAXI | );
		//Edge edge662(152, 151, TAXI | ); repeat of edge 661
		Edge edge663(152, 153, TAXI | );
		Edge edge664(153, 139, TAXI | );
		Edge edge665(153, 152, TAXI | );
		Edge edge666(153, 154, TAXI | BUS);
		Edge edge667(153, 166, TAXI | );
		Edge edge668(153, 167, TAXI | );
		Edge edge669(152, 124, BUS); 
		Edge edge670(153, 180, BUS);
		Edge edge671(153, 184, BUS);
		Edge edge672(153, 111, UNDERGROUND);
		Edge edge673(153, 140, UNDERGROUND);
		Edge edge674(153, 163, UNDERGROUND);
		Edge edge675(153, 163, UNDERGROUND);
		Edge edge676(153, 185, UNDERGROUND);
		Edge edge677(154, 139, TAXI | );
		Edge edge678(154, 140, TAXI | BUS);
		Edge edge679(154, 153, TAXI | );
		Edge edge680(154, 155, TAXI | );
		Edge edge681(155, 156, TAXI | );
		Edge edge682(155, 167, TAXI | );
		Edge edge683(155, 168, TAXI | );
		Edge edge684(156, 140, TAXI | BUS);
		Edge edge685(156, 155, TAXI | );
		Edge edge686(156, 157, TAXI | BUS);
		Edge edge687(156, 169, TAXI | );
		Edge edge688(156, 154, BUS);
		Edge edge689(156, 184, BUS);
		Edge edge690(157, 156, TAXI | );
		Edge edge691(157, 158, TAXI | );
		Edge edge692(157, 170, TAXI | );
		Edge edge693(157, 133, BUS);
		Edge edge694(157, 142, BUS);
		Edge edge695(157, 156, BUS);
		Edge edge696(157, 185, BUS);
		Edge edge697(157, 115, RIVER);
		Edge edge698(157, 194, RIVER);
		Edge edge699(158, 141, TAXI | );
		Edge edge700(158, 142, TAXI | );
		Edge edge701(158, 157, TAXI | );
		Edge edge702(158, 159, TAXI | );
		Edge edge703(159, 158, TAXI | );
		Edge edge704(159, 170, TAXI | );
		Edge edge705(159, 172, TAXI | );
		Edge edge706(159, 186, TAXI | );
		Edge edge707(159, 198, TAXI | );
		Edge edge708(160, 128, TAXI | );
		Edge edge709(160, 143, TAXI | );
		Edge edge710(160, 161, TAXI | );
		Edge edge711(160, 173, TAXI | );
		Edge edge712(161, 135, TAXI | BUS);
		Edge edge713(161, 160, TAXI | );
		Edge edge714(161, 174, TAXI | );
		Edge edge715(161, 107, BUS);
		Edge edge716(161, 128, BUS);
		Edge edge717(161, 199, BUS);
		Edge edge718(162, 136, TAXI | );
		Edge edge719(162, 175, TAXI | );
		Edge edge720(163, 146, TAXI | );
		Edge edge721(163, 177, TAXI | );
		Edge edge722(163, 144, BUS);
		Edge edge723(164, 176, BUS);
		Edge edge724(163, 191, BUS);
		Edge edge725(163, 111, UNDERGROUND);
		Edge edge726(163, 153, UNDERGROUND);
		Edge edge727(164, 147, TAXI | );
		Edge edge728(164, 148, TAXI | );
		Edge edge729(164, 178, TAXI | );
		Edge edge730(164, 179, TAXI | );
		Edge edge731(165, 149, TAXI | );
		Edge edge732(165, 151, TAXI | );
		Edge edge733(165, 179, TAXI | );
		Edge edge734(165, 180, TAXI | BUS);
		Edge edge735(165, 123, BUS);
		Edge edge736(165, 191, BUS);
		Edge edge737(166, 151, TAXI | );
		Edge edge738(166, 153, TAXI | );
		Edge edge739(166, 181, TAXI | );
		Edge edge740(166, 183, TAXI | );
		Edge edge741(167, 153, TAXI | );
		Edge edge742(167, 155, TAXI | );
		Edge edge743(167, 168, TAXI | );
		Edge edge744(167, 183, TAXI | );
		Edge edge745(168, 155, TAXI | );
		Edge edge746(168, 167, TAXI | );
		Edge edge747(168, 184, TAXI | );
		Edge edge748(169, 156, TAXI | );
		Edge edge749(169, 184, TAXI | );
		Edge edge750(170, 157, TAXI | );
		Edge edge751(170, 159, TAXI | );
		Edge edge752(170, 185, TAXI | );
		Edge edge753(171, 173, TAXI | );
		Edge edge754(171, 175, TAXI | );
		Edge edge755(171, 199, TAXI | );
		Edge edge756(172, 128, TAXI | );
		Edge edge757(172, 159, TAXI | );
		Edge edge758(172, 187, TAXI | );
		Edge edge759(173, 160, TAXI | );
		Edge edge760(173, 171, TAXI | );
		Edge edge761(173, 174, TAXI | );
		Edge edge762(173, 188, TAXI | );
		Edge edge763(174, 161, TAXI | );
		Edge edge764(174, 173, TAXI | );
		Edge edge765(174, 175, TAXI | );
		Edge edge766(175, 162, TAXI | );
		Edge edge767(175, 171, TAXI | );
		Edge edge768(175, 174, TAXI | );
		Edge edge769(176, 177, TAXI | );
		Edge edge770(176, 189, TAXI | );
		Edge edge771(176, 163, BUS);
		Edge edge772(176, 190, BUS);
		Edge edge773(177, 144, TAXI | );
		Edge edge774(177, 163, TAXI | );
		Edge edge775(177, 176, TAXI | );
		Edge edge776(178, 164, TAXI | );
		Edge edge777(178, 189, TAXI | );
		Edge edge778(178, 191, TAXI | );
		Edge edge779(179, 164, TAXI | );
		Edge edge780(179, 165, TAXI | );
		Edge edge781(179, 191, TAXI | );
		Edge edge782(180, 165, TAXI | );
		Edge edge783(180, 181, TAXI | );
		Edge edge784(180, 193, TAXI | );
		Edge edge785(180, 153, BUS);
		Edge edge786(180, 165, BUS);
		Edge edge787(180, 184, BUS);
		Edge edge788(180, 190, BUS);
		Edge edge789(181, 166, TAXI | );
		Edge edge790(181, 180, TAXI | );
		Edge edge791(181, 182, TAXI | );
		Edge edge792(181, 192, TAXI | );
		Edge edge793(182, 181, TAXI | );
		Edge edge794(182, 183, TAXI | );
		Edge edge795(182, 195, TAXI | );
		Edge edge796(183, 166, TAXI | );
		Edge edge797(183, 167, TAXI | );
		Edge edge798(183, 182, TAXI | );
		Edge edge799(183, 196, TAXI | );
		Edge edge800(184, 168, TAXI | );
		Edge edge801(184, 169, TAXI | );
		Edge edge802(184, 185, TAXI | BUS);
		Edge edge803(184, 196, TAXI | );
		Edge edge804(184, 197, TAXI | );
		Edge edge805(184, 153, BUS);
		Edge edge806(184, 156, BUS);
		Edge edge807(184, 180, BUS);
		Edge edge808(185, 170, TAXI | );
		Edge edge809(185, 184, TAXI | BUS);
		Edge edge810(185, 186, TAXI | );
		Edge edge811(185, 157, BUS);
		Edge edge812(185, 187, BUS);
		Edge edge813(185, 128, UNDERGROUND);
		Edge edge814(185, 153, UNDERGROUND);
		Edge edge815(186, 159, TAXI | );
		Edge edge816(186, 185, TAXI | );
		Edge edge817(186, 198, TAXI | );
		Edge edge818(187, 172, TAXI | );
		Edge edge819(187, 188, TAXI | );
		Edge edge820(187, 198, TAXI | );
		Edge edge821(187, 128, BUS);
		Edge edge822(187, 185, BUS);
		Edge edge823(188, 128, TAXI | );
		Edge edge824(188, 173, TAXI | );
		Edge edge825(188, 187, TAXI | );
		Edge edge826(188, 199, TAXI | );
		Edge edge827(189, 176, TAXI | );
		Edge edge828(189, 178, TAXI | );
		Edge edge829(189, 190, TAXI | );
		Edge edge830(190, 189, TAXI | );
		Edge edge831(190, 191, TAXI | );
		Edge edge832(190, 192, TAXI | );
		Edge edge833(190, 176, BUS);
		Edge edge834(190, 180, BUS);
		Edge edge835(190, 191, BUS);
		Edge edge836(191, 178, TAXI | );
		Edge edge837(191, 179, TAXI | );
		Edge edge838(191, 190, TAXI | BUS);
		Edge edge839(191, 192, TAXI | );
		Edge edge840(191, 163, BUS);
		Edge edge841(191, 165, BUS);
		Edge edge842(192, 190, TAXI | );
		Edge edge843(192, 191, TAXI | );
		Edge edge844(192, 194, TAXI | );
		Edge edge845(193, 180, TAXI | );
		Edge edge846(193, 181, TAXI | );
		Edge edge847(193, 194, TAXI | );
		Edge edge848(194, 192, TAXI | );
		Edge edge849(195, 182, TAXI | );
		Edge edge850(195, 194, TAXI | );
		Edge edge851(195, 197, TAXI | );
		Edge edge852(196, 183, TAXI | );
		Edge edge853(196, 184, TAXI | );
		Edge edge854(196, 197, TAXI | );
		Edge edge855(197, 184, TAXI | );
		Edge edge856(197, 195, TAXI | );
		Edge edge857(197, 196, TAXI | );
		Edge edge858(198, 159, TAXI | );
		Edge edge859(198, 186, TAXI | );
		Edge edge860(198, 187, TAXI | );
		Edge edge861(198, 199, TAXI | );
		Edge edge862(199, 171, TAXI | );
		Edge edge863(199, 188, TAXI | );
		Edge edge864(199, 198, TAXI | );
		Edge edge865(199, 128, BUS);
		Edge edge866(199, 161, BUS);
		//edges kelly added for station 200: 
		Edge edge867(200, 199, TAXI);
		Edge edge868(200, 173, TAXI);
		Edge edge869(200, 175, TAXI);

		Edge edge870(199, 200, TAXI);
		Edge edge871(173, 200, TAXI);
		Edge edge872(175, 200, TAXI);
	
		
		//create each station and add its relevant edges to its list of edges
		//add the newly created station to the board 
		
		for(int i = 1; i <= 200; i++) { //199 stations on the board, ranging from 1 to 200
			
			Station curStation(i, edges); //station number is i
			
			//the hard part: determining which edges to put into the edge vector 
			//based on what station we are 
			//the current station we are right now is the station with station number i
			if(i == 1)
				curStation.setEdges(edge1, edge2, edge3, edge4);
			else if(i == 2)
				curStation.setEdges(edge5, edge6);
			else if(i == 3)
				curStation.setEdges(edge7, edge8, edge9, edge10, edge11);
			else if(i == 4)
				curStation.setEdges(edge12, edge13;
			else if(i == 5)
				curStation.setEdges(edge15, edge16);
			else if(i == 6)
				curStation.setEdges(edge16, edge17);
			else if(i == 7)
				curStation.setEdges(edge18, edge19, edge20);
			else if(i == 8)
				curStation.setEdges(edge21, edge22, edge23);
			else if(i == 9)
				curStation.setEdges(edge24, edge25, edge26);
			else if(i == 10)
				curStation.setEdges(edge27, edge28, edge29, edge30);
			else if(i == 11)
				curStation.setEdges(edge31, edge32, edge33);
			else if(i == 12)
				curStation.setEdges(edge34, edge35);
			else if(i == 13)
				curStation.setEdges(edge36, edge37, edge38, edge39, edge40, edge41, edge42, edge43);
			else if(i == 14)
				curStation.setEdges(edge44, edge45, edge46);
			else if(i == 15)
				curStation.setEdges(edge47, edge48, edge49, edge50, edge51, edge52, edge53);
			else if(i == 16)
				curStation.setEdges(edge54, edge55, edge56, edge57);
			else if(i == 17)
				curStation.setEdges(edge58, edge59, edge60);
			else if(i == 18)
				curStation.setEdges(edge61, edge62, edge63);
			else if(i == 19)
				curStation.setEdges(edge64, edge65, edge66);
			else if(i == 20)
				curStation.setEdges(edge67, edge68, edge69);
			else if(i == 21)
				curStation.setEdges(edge70, edge71);
			else if(i == 22)
				curStation.setEdges(edge72, edge73, edge74, edge75, edge76);
			else if(i == 23)
				curStation.setEdges(edge77, edge78, edge79, edge80, edge81);
			else if(i == 24)
				curStation.setEdges(edge82, edge83, edge84);
			else if(i == 25)
				curStation.setEdges(edge85, edge86, edge87);
			else if(i == 26)
				curStation.setEdges(edge88, edge89, edge90);
			else if(i == 27)
				curStation.setEdges(edge91, edge92, edge93);
			else if(i == 28)
				curStation.setEdges(edge94, edge95, edge96, edge97);
			else if(i == 29)
				curStation.setEdges(edge98, edge99, edge100, edge101, edge102, edge103, edge104);
			else if(i == 30)
				curStation.setEdges(edge105, edge106);
			else if(i == 31)
				curStation.setEdges(edge107, edge108, edge109);
			else if(i == 32)
				curStation.setEdges(edge110, edge111, edge112, edge113);
			else if(i == 33)
				curStation.setEdges(edge114, edge115, edge116, edge117);
			else if(i == 34)
				curStation.setEdges(edge118, edge119, edge120, edge121, edge122, edge123);
			else if(i == 35)
				curStation.setEdges(edge124, edge125, edge126, edge127);
			else if(i == 36)
				curStation.setEdges(edge128, edge129, edge130);
			else if(i == 37)
				curStation.setEdges(edge131, edge132, edge133, edge134);
			else if(i == 38)
				curStation.setEdges(edge135, edge136, edge137, edge138);
			else if(i == 39)
				curStation.setEdges(edge139, edge140, edge141, edge142);
			else if(i == 40)
				curStation.setEdges(edge143, edge144, edge145, edge146);
			else if(i == 41)
				curStation.setEdges(edge147, edge148, edge149, edge150, edge151, edge152, edge153);
			else if(i == 42)
				curStation.setEdges(edge154, edge155, edge156, edge157, edge158);
			else if(i == 43)
				curStation.setEdges(edge159, edge160, edge161);
			else if(i == 44)
				curStation.setEdges(edge162, edge163, edge164);
			else if(i == 45)
				curStation.setEdges(edge165, edge166, edge167, edge168, edge169);
			else if(i == 46)
				curStation.setEdges(edge170, edge171, edge172, edge173, edge174, edge175, edge176, edge177, edge178, edge179, edge180);
			else if(i == 47)
				curStation.setEdges(edge181, edge182, edge183);
			else if(i == 48)
				curStation.setEdges(edge184, edge185, edge186, edge187);
			else if(i == 49)
				curStation.setEdges(edge188, edge189, edge190);
			else if(i == 50)
				curStation.setEdges(edge191, edge192, edge193);
			else if(i == 51)
				curStation.setEdges(edge194, edge195, edge196, edge197, edge198);
			else if(i == 52)
				curStation.setEdges(edge199, edge200, edge201, edge202, edge203, edge204, edge205, edge206);
			else if(i == 53)
				curStation.setEdges(edge207, edge208, edge209);
			else if(i == 54)
				curStation.setEdges(edge210, edge211, edge212, edge213);
			else if(i == 55)
				curStation.setEdges(edge214, edge215, edge216, edge217);
			else if(i == 56)
				curStation.setEdges(edge218, edge219);
			else if(i == 57)
				curStation.setEdges(edge220, edge221, edge222);
			else if(i == 58)
				curStation.setEdges(edge223, edge224, edge225, edge226, edge227, edge228, edge229, edge230, edge231, edge232);
			else if(i == 59)
				curStation.setEdges(edge233, edge234, edge235, edge236);
			else if(i == 60)
				curStation.setEdges(edge237, edge238, edge239);
			else if(i == 61)
				curStation.setEdges(edge240, edge241, edge242, edge243, edge244);
			else if(i == 62)
				curStation.setEdges(edge245, edge246, edge247, edge248);
			else if(i == 63)
				curStation.setEdges(edge249, edge250, edge251, edge252, edge253, edge254, edge255);
			else if(i == 64)
				curStation.setEdges(edge256, edge257, edge258);
			else if(i == 65)
				curStation.setEdges(edge259, edge260, edge261, edge262, edge263, edge264);
			else if(i == 66)
				curStation.setEdges(edge265, edge266, edge267, edge268);
			else if(i == 67)
				curStation.setEdges(edge269, edge270, edge271, edge272, edge273, edge274, edge275, edge276, edge277, edge278, edge279, edge280, edge281);
			else if(i == 68)
				curStation.setEdges(edge282, edge283, edge284, edge285);
			else if(i == 69)
				curStation.setEdges(edge286, edge287, edge288, edge289);
			else if(i == 70)
				curStation.setEdges(edge290, edge291, edge292);
			else if(i == 71)
				curStation.setEdges(edge293, edge294, edge296);
			else if(i == 72)
				curStation.setEdges(edge297, edge298, edge299, edge300, edge301, edge302);
			else if(i == 73)
				curStation.setEdges(edge303, edge304, edge305);
			else if(i == 74)
				curStation.setEdges(edge306, edge307, edge308, edge309, edge310);
			else if(i == 75)
				curStation.setEdges(edge311, edge312, edge313, edge314);
			else if(i == 76)
				curStation.setEdges(edge315, edge316, edge317, edge318);
			else if(i == 77)
				curStation.setEdges(edge319, edge320, edge321, edge322, edge323, edge324, edge325);
			else if(i == 78)
				curStation.setEdges(edge326, edge327, edge328, edge329);
			else if(i == 79)
				curStation.setEdges(edge330, edge331, edge332, edge333, edge334, edge335, edge336, edge337);
			else if(i == 80)
				curStation.setEdges(edge338, edge339, edge340);
			else if(i == 81)
				curStation.setEdges(edge341, edge342, edge343, edge344);
			else if(i == 82)
				curStation.setEdges(edge345, edge346, edge347, edge348, edge349, edge350, edge351);
			else if(i == 83)
				curStation.setEdges(edge352, edge353);
			else if(i == 84)
				curStation.setEdges(edge354, edge355);
			else if(i == 85)
				curStation.setEdges(edge356, edge357, edge358);
			else if(i == 86)
				curStation.setEdges(edge359, edge360, edge361, edge362, edge363, edge364, edge365);
			else if(i == 87)
				curStation.setEdges(edge366, edge367, edge368, edge369, edge370);
			else if(i == 88)
				curStation.setEdges(edge371, edge372, edge373);
			else if(i == 89)
				curStation.setEdges(edge374, edge375, edge376, edge377, edge378, edge379, edge380, edge381);
			else if(i == 90)
				curStation.setEdges(edge382, edge383, edge384);
			else if(i == 91)
				curStation.setEdges(edge385, edge386, edge387, edge388, edge389);
			else if(i == 92)
				curStation.setEdges(edge390, edge391, edge392);
			else if(i == 93)
				curStation.setEdges(edge393, edge394, edge395);
			else if(i == 94)
				curStation.setEdges(edge396, edge397, edge398, edge399, edge400);
			else if(i == 95)
				curStation.setEdges(edge401, edge402, edge403);
			else if(i == 96)
				curStation.setEdges(edge404, edge405, edge406);
			else if(i == 97)
				curStation.setEdges(edge407, edge408, edge409, edge410);
			else if(i == 98)
				curStation.setEdges(edge411, edge412, edge413, edge414);
			else if(i == 99)
				curStation.setEdges(edge415, edge416, edge417, edge418);
			else if(i == 100)
				curStation.setEdges(edge419, edge420, edge421, edge422, edge423, edge424, edge425, edge426);
			else if(i == 101)
				curStation.setEdges(edge427, edge428, edge429, edge430);
			else if(i == 102)
				curStation.setEdges(edge431, edge432, edge433);
			else if(i == 103)
				curStation.setEdges(edge434, edge435, edge436);
			else if(i == 104)
				curStation.setEdges(edge437, edge438);
			else if(i == 105)
				curStation.setEdges(edge439, edge440, edge441, edge442, edge443, edge444, edge445, edge446);
			else if(i == 106)
				curStation.setEdges(edge447, edge448);
			else if(i == 107)
				curStation.setEdges(edge449, edge450, edge451, edge452, edge453, edge454);
			else if(i == 108)
				curStation.setEdges(edge455, edge456, edge457, edge458, edge459, edge460);
			else if(i == 109)
				curStation.setEdges(edge461, edge462, edge463, edge464);
			else if(i == 110)
				curStation.setEdges(edge465, edge466, edge467, edge468);
			else if(i == 111)
				curStation.setEdges(edge469, edge470, edge471, edge472, edge473, edge474, edge475, edge476);
			else if(i == 112)
				curStation.setEdges(edge477, edge478, edge479, edge480);
			else if(i == 113)
				curStation.setEdges(edge481, edge482, edge483);
			else if(i == 114)
				curStation.setEdges(edge484, edge485, edge486, edge487, edge488, edge489);
			else if(i == 115)
				curStation.setEdges(edge490, edge491, edge492, edge493, edge494, edge495);
			else if(i == 116)
				curStation.setEdges(edge496, edge497, edge498, edge499, edge500, edge501, edge502, edge503, edge504);
			else if(i == 117)
				curStation.setEdges(edge505, edge506, edge507, edge508);
			else if(i == 118)
				curStation.setEdges(edge509, edge510, edge511, edge512, edge513);
			else if(i == 119)
				curStation.setEdges(edge514, edge515, edge516);
			else if(i == 120)
				curStation.setEdges(edge517, edge518);
			else if(i == 121)
				curStation.setEdges(edge519, edge520, edge521);
			else if(i == 122)
				curStation.setEdges(edge522, edge523, edge524, edge525, edge526);
			else if(i == 123)
				curStation.setEdges(edge527, edge528, edge529, edge530, edge531, edge532, edge533);
			else if(i == 124)
				curStation.setEdges(edge534, edge535, edge536, edge537, edge538, edge539, edge540);
			else if(i == 125)
				curStation.setEdges(edge541, edge542, edge543);
			else if(i == 126)
				curStation.setEdges(edge544, edge545, edge546, edge547);
			else if(i == 127)
				curStation.setEdges(edge548, edge549, edge550, edge551, edge552, edge553);
			else if(i == 128)
				curStation.setEdges(edge554, edge555, edge556, edge557, edge558, edge559, edge560, edge561, edge562, edge563, edge564, edge565, edge566);
			else if(i == 129)
				curStation.setEdges(edge567, edge568, edge569, edge570, edge571);
			else if(i == 130)
				curStation.setEdges(edge572, edge573, edge574);
			else if(i == 131)
				curStation.setEdges(edge575, edge576, edge577);
			else if(i == 132)
				curStation.setEdges(edge578, edge579);
			else if(i == 133)
				curStation.setEdges(edge580, edge581, edge582, edge583);
			else if(i == 134)
				curStation.setEdges(edge584, edge585, edge586, edge587);
			else if(i == 135)
				curStation.setEdges(edge588, edge589, edge590, edge591, edge592, edge593);
			else if(i == 136)
				curStation.setEdges(edge594, edge595, edge596);
			else if(i == 137)
				curStation.setEdges(edge597, edge598);
			else if(i == 138)
				curStation.setEdges(edge599, edge600, edge601);
			else if(i == 139)
				curStation.setEdges(edge602, edge603, edge604, edge605);
			else if(i == 140)
				curStation.setEdges(edge606, edge607, edge608, edge609, edge610, edge611, edge612, edge613, edge614, edge615);
			else if(i == 141)
				curStation.setEdges(edge616, edge617, edge618);
			else if(i == 142)
				curStation.setEdges(edge619, edge620, edge621, edge622, edge623);
			else if(i == 143)
				curStation.setEdges(edge624, edge625, edge626, edge627, edge628);
			else if(i == 144)
				curStation.setEdges(edge629, edge630, edge631, edge632, edge633, edge634, edge636, edge637);
			else if(i == 145)
				curStation.setEdges(edge638, edge639, edge640);
			else if(i == 146)
				curStation.setEdges(edge641, edge642, edge643);
			else if(i == 147)
				curStation.setEdges(edge644, edge645);
			else if(i == 148)
				curStation.setEdges(edge646, edge647, edge648);
			else if(i == 149)
				curStation.setEdges(edge649, edge650, edge651, edge652);
			else if(i == 150)
				curStation.setEdges(edge653, edge654, edge655);
			else if(i == 151)
				curStation.setEdges(edge656, edge657, edge658, edge659);
			else if(i == 152)
				curStation.setEdges(edge660, edge661, edge663, edge669);
			else if(i == 153)
				curStation.setEdges(edge664, edge665, edge666, edge667, edge668, edge670, edge671, edge672, edge673, edge674, edge675, edge676);
			else if(i == 154)
				curStation.setEdges(edge677, edge678, edge679, edge680);
			else if(i == 155)
				curStation.setEdges(edge681, edge682, edge683);
			else if(i == 156)
				curStation.setEdges(edge684, edge685, edge686, edge687, edge688, edge689);
			else if(i == 157)
				curStation.setEdges(edge690, edge691, edge692, edge693, edge694, edge695, edge696, edge697, edge698);
			else if(i == 158)
				curStation.setEdges(edge699, edge700, edge701, edge702);
			else if(i == 159)
				curStation.setEdges(edge703, edge704, edge705, edge706, edge707);
			else if(i == 160)
				curStation.setEdges(edge708, edge709, edge710, edge711);
			else if(i == 161)
				curStation.setEdges(edge712, edge713, edge714, edge715, edge716, edge717);
			else if(i == 162)
				curStation.setEdges(edge718, edge719);
			else if(i == 163)
				curStation.setEdges(edge720, edge721, edge722, edge724, edge725, edge726);
			else if(i == 164)
				curStation.setEdges(edge723, edge727, edge728, edge729, edge730);
			else if(i == 165)
				curStation.setEdges(edge731, edge732, edge733, edge734, edge735, edge736);
			else if(i == 166)
				curStation.setEdges(edge737, edge738, edge739, edge740);
			else if(i == 167)
				curStation.setEdges(edge741, edge742, edge743, edge744);
			else if(i == 168)
				curStation.setEdges(edge745, edge746, edge747);
			else if(i == 169)
				curStation.setEdges(edge748, edge749);
			else if(i == 170)
				curStation.setEdges(edge750, edge751, edge752);
			else if(i == 171)
				curStation.setEdges(edge753, edge754, edge755);
			else if(i == 172)
				curStation.setEdges(edge756, edge757, edge758);
			else if(i == 173)
				curStation.setEdges(edge759, edge760, edge761, edge762, edge871);
			else if(i == 174)
				curStation.setEdges(edge763, edge764, edge765);
			else if(i == 175)
				curStation.setEdges(edge766, edge767, edge768, edge872);
			else if(i == 176)
				curStation.setEdges(edge769, edge770, edge771, edge772);
			else if(i == 177)
				curStation.setEdges(edge773, edge774, edge775);
			else if(i == 178)
				curStation.setEdges(edge776, edge777, edge778);
			else if(i == 179)
				curStation.setEdges(edge779, edge780, edge781);
			else if(i == 180)
				curStation.setEdges(edge782, edge783, edge784, edge785, edge786, edge787, edge788);
			else if(i == 181)
				curStation.setEdges(edge789, edge790, edge791, edge792);
			else if(i == 182)
				curStation.setEdges(edge793, edge794, edge795);
			else if(i == 183)
				curStation.setEdges(edge796, edge797, edge798, edge799);
			else if(i == 184)
				curStation.setEdges(edge800, edge801, edge802, edge803, edge804, edge805, edge806, edge807);
			else if(i == 185)
				curStation.setEdges(edge808, edge809, edge810, edge811, edge812, edge813, edge814);
			else if(i == 186)
				curStation.setEdges(edge815, edge816, edge817);
			else if(i == 187)
				curStation.setEdges(edge818, edge819, edge820, edge821, edge822);
			else if(i == 188)
				curStation.setEdges(edge823, edge824, edge825, edge826);
			else if(i == 189)
				curStation.setEdges(edge827, edge828, edge829);
			else if(i == 190)
				curStation.setEdges(edge830, edge831, edge832, edge833, edge834, edge835);
			else if(i == 191)
				curStation.setEdges(edge836, edge837, edge838, edge839, edge840, edge841);
			else if(i == 192)
				curStation.setEdges(edge842, edge843, edge844);
			else if(i == 193)
				curStation.setEdges(edge845, edge846, edge847);
			else if(i == 194)
				curStation.setEdges(edge848);
			else if(i == 195)
				curStation.setEdges(edge849, edge850, edge851);
			else if(i == 196)
				curStation.setEdges(edge852, edge853, edge854);
			else if(i == 197)
				curStation.setEdges(edge855, edge856, edge857);
			else if(i == 198)
				curStation.setEdges(edge858, edge859, edge860, edge861);
			else if(i == 199)
				curStation.setEdges(edge862, edge863, edge864, edge865, edge866, edge870);
			else if(i == 200)
				curStation.setEdges(edge867, edge868, edge869);
			
			
			board.push_back(curStation);
		}
		
		return board;
	}
