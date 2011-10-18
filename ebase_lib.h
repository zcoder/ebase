/* 
 * File:   base_lib.h
 * Author: zhenka
 *
 * Created on July 4, 2011, 3:56 PM
 */

#ifndef BASE64LIB_H
#define	BASE64LIB_H

#include <stdint.h>

int base64_decode_block(const char*, const uint32_t, char*, const uint32_t, const char*);
int base64_encode_block(const char*, const uint32_t, char*, const uint32_t, const char*);

static const char etable_rfc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
static const char etable_url[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_\0";
static const char etable_xmlt[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.-\0";
static const char etable_xmli[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_:\0";

#define db64_rfc(_)                             \
    ((_) == 'A' ? 0                             \
   : (_) == 'B' ? 1                             \
   : (_) == 'C' ? 2                             \
   : (_) == 'D' ? 3                             \
   : (_) == 'E' ? 4                             \
   : (_) == 'F' ? 5                             \
   : (_) == 'G' ? 6                             \
   : (_) == 'H' ? 7                             \
   : (_) == 'I' ? 8                             \
   : (_) == 'J' ? 9                             \
   : (_) == 'K' ? 10                            \
   : (_) == 'L' ? 11                            \
   : (_) == 'M' ? 12                            \
   : (_) == 'N' ? 13                            \
   : (_) == 'O' ? 14                            \
   : (_) == 'P' ? 15                            \
   : (_) == 'Q' ? 16                            \
   : (_) == 'R' ? 17                            \
   : (_) == 'S' ? 18                            \
   : (_) == 'T' ? 19                            \
   : (_) == 'U' ? 20                            \
   : (_) == 'V' ? 21                            \
   : (_) == 'W' ? 22                            \
   : (_) == 'X' ? 23                            \
   : (_) == 'Y' ? 24                            \
   : (_) == 'Z' ? 25                            \
   : (_) == 'a' ? 26                            \
   : (_) == 'b' ? 27                            \
   : (_) == 'c' ? 28                            \
   : (_) == 'd' ? 29                            \
   : (_) == 'e' ? 30                            \
   : (_) == 'f' ? 31                            \
   : (_) == 'g' ? 32                            \
   : (_) == 'h' ? 33                            \
   : (_) == 'i' ? 34                            \
   : (_) == 'j' ? 35                            \
   : (_) == 'k' ? 36                            \
   : (_) == 'l' ? 37                            \
   : (_) == 'm' ? 38                            \
   : (_) == 'n' ? 39                            \
   : (_) == 'o' ? 40                            \
   : (_) == 'p' ? 41                            \
   : (_) == 'q' ? 42                            \
   : (_) == 'r' ? 43                            \
   : (_) == 's' ? 44                            \
   : (_) == 't' ? 45                            \
   : (_) == 'u' ? 46                            \
   : (_) == 'v' ? 47                            \
   : (_) == 'w' ? 48                            \
   : (_) == 'x' ? 49                            \
   : (_) == 'y' ? 50                            \
   : (_) == 'z' ? 51                            \
   : (_) == '0' ? 52                            \
   : (_) == '1' ? 53                            \
   : (_) == '2' ? 54                            \
   : (_) == '3' ? 55                            \
   : (_) == '4' ? 56                            \
   : (_) == '5' ? 57                            \
   : (_) == '6' ? 58                            \
   : (_) == '7' ? 59                            \
   : (_) == '8' ? 60                            \
   : (_) == '9' ? 61                            \
   : (_) == '+' ? 62                            \
   : (_) == '/' ? 63                            \
   : (_) == '=' ? 64                            \
   : 128)

#define db64_url(_)                             \
    ((_) == 'A' ? 0                             \
   : (_) == 'B' ? 1                             \
   : (_) == 'C' ? 2                             \
   : (_) == 'D' ? 3                             \
   : (_) == 'E' ? 4                             \
   : (_) == 'F' ? 5                             \
   : (_) == 'G' ? 6                             \
   : (_) == 'H' ? 7                             \
   : (_) == 'I' ? 8                             \
   : (_) == 'J' ? 9                             \
   : (_) == 'K' ? 10                            \
   : (_) == 'L' ? 11                            \
   : (_) == 'M' ? 12                            \
   : (_) == 'N' ? 13                            \
   : (_) == 'O' ? 14                            \
   : (_) == 'P' ? 15                            \
   : (_) == 'Q' ? 16                            \
   : (_) == 'R' ? 17                            \
   : (_) == 'S' ? 18                            \
   : (_) == 'T' ? 19                            \
   : (_) == 'U' ? 20                            \
   : (_) == 'V' ? 21                            \
   : (_) == 'W' ? 22                            \
   : (_) == 'X' ? 23                            \
   : (_) == 'Y' ? 24                            \
   : (_) == 'Z' ? 25                            \
   : (_) == 'a' ? 26                            \
   : (_) == 'b' ? 27                            \
   : (_) == 'c' ? 28                            \
   : (_) == 'd' ? 29                            \
   : (_) == 'e' ? 30                            \
   : (_) == 'f' ? 31                            \
   : (_) == 'g' ? 32                            \
   : (_) == 'h' ? 33                            \
   : (_) == 'i' ? 34                            \
   : (_) == 'j' ? 35                            \
   : (_) == 'k' ? 36                            \
   : (_) == 'l' ? 37                            \
   : (_) == 'm' ? 38                            \
   : (_) == 'n' ? 39                            \
   : (_) == 'o' ? 40                            \
   : (_) == 'p' ? 41                            \
   : (_) == 'q' ? 42                            \
   : (_) == 'r' ? 43                            \
   : (_) == 's' ? 44                            \
   : (_) == 't' ? 45                            \
   : (_) == 'u' ? 46                            \
   : (_) == 'v' ? 47                            \
   : (_) == 'w' ? 48                            \
   : (_) == 'x' ? 49                            \
   : (_) == 'y' ? 50                            \
   : (_) == 'z' ? 51                            \
   : (_) == '0' ? 52                            \
   : (_) == '1' ? 53                            \
   : (_) == '2' ? 54                            \
   : (_) == '3' ? 55                            \
   : (_) == '4' ? 56                            \
   : (_) == '5' ? 57                            \
   : (_) == '6' ? 58                            \
   : (_) == '7' ? 59                            \
   : (_) == '8' ? 60                            \
   : (_) == '9' ? 61                            \
   : (_) == '-' ? 62                            \
   : (_) == '_' ? 63                            \
   : (_) == '\0'? 64                            \
   : 128)

#define db64_xmlt(_)                                 \
    ((_) == 'A' ? 0                             \
   : (_) == 'B' ? 1                             \
   : (_) == 'C' ? 2                             \
   : (_) == 'D' ? 3                             \
   : (_) == 'E' ? 4                             \
   : (_) == 'F' ? 5                             \
   : (_) == 'G' ? 6                             \
   : (_) == 'H' ? 7                             \
   : (_) == 'I' ? 8                             \
   : (_) == 'J' ? 9                             \
   : (_) == 'K' ? 10                            \
   : (_) == 'L' ? 11                            \
   : (_) == 'M' ? 12                            \
   : (_) == 'N' ? 13                            \
   : (_) == 'O' ? 14                            \
   : (_) == 'P' ? 15                            \
   : (_) == 'Q' ? 16                            \
   : (_) == 'R' ? 17                            \
   : (_) == 'S' ? 18                            \
   : (_) == 'T' ? 19                            \
   : (_) == 'U' ? 20                            \
   : (_) == 'V' ? 21                            \
   : (_) == 'W' ? 22                            \
   : (_) == 'X' ? 23                            \
   : (_) == 'Y' ? 24                            \
   : (_) == 'Z' ? 25                            \
   : (_) == 'a' ? 26                            \
   : (_) == 'b' ? 27                            \
   : (_) == 'c' ? 28                            \
   : (_) == 'd' ? 29                            \
   : (_) == 'e' ? 30                            \
   : (_) == 'f' ? 31                            \
   : (_) == 'g' ? 32                            \
   : (_) == 'h' ? 33                            \
   : (_) == 'i' ? 34                            \
   : (_) == 'j' ? 35                            \
   : (_) == 'k' ? 36                            \
   : (_) == 'l' ? 37                            \
   : (_) == 'm' ? 38                            \
   : (_) == 'n' ? 39                            \
   : (_) == 'o' ? 40                            \
   : (_) == 'p' ? 41                            \
   : (_) == 'q' ? 42                            \
   : (_) == 'r' ? 43                            \
   : (_) == 's' ? 44                            \
   : (_) == 't' ? 45                            \
   : (_) == 'u' ? 46                            \
   : (_) == 'v' ? 47                            \
   : (_) == 'w' ? 48                            \
   : (_) == 'x' ? 49                            \
   : (_) == 'y' ? 50                            \
   : (_) == 'z' ? 51                            \
   : (_) == '0' ? 52                            \
   : (_) == '1' ? 53                            \
   : (_) == '2' ? 54                            \
   : (_) == '3' ? 55                            \
   : (_) == '4' ? 56                            \
   : (_) == '5' ? 57                            \
   : (_) == '6' ? 58                            \
   : (_) == '7' ? 59                            \
   : (_) == '8' ? 60                            \
   : (_) == '9' ? 61                            \
   : (_) == '.' ? 62                            \
   : (_) == '-' ? 63                            \
   : (_) == '\0'? 64                            \
   : 128)


#define db64_xmli(_)                                 \
    ((_) == 'A' ? 0                             \
   : (_) == 'B' ? 1                             \
   : (_) == 'C' ? 2                             \
   : (_) == 'D' ? 3                             \
   : (_) == 'E' ? 4                             \
   : (_) == 'F' ? 5                             \
   : (_) == 'G' ? 6                             \
   : (_) == 'H' ? 7                             \
   : (_) == 'I' ? 8                             \
   : (_) == 'J' ? 9                             \
   : (_) == 'K' ? 10                            \
   : (_) == 'L' ? 11                            \
   : (_) == 'M' ? 12                            \
   : (_) == 'N' ? 13                            \
   : (_) == 'O' ? 14                            \
   : (_) == 'P' ? 15                            \
   : (_) == 'Q' ? 16                            \
   : (_) == 'R' ? 17                            \
   : (_) == 'S' ? 18                            \
   : (_) == 'T' ? 19                            \
   : (_) == 'U' ? 20                            \
   : (_) == 'V' ? 21                            \
   : (_) == 'W' ? 22                            \
   : (_) == 'X' ? 23                            \
   : (_) == 'Y' ? 24                            \
   : (_) == 'Z' ? 25                            \
   : (_) == 'a' ? 26                            \
   : (_) == 'b' ? 27                            \
   : (_) == 'c' ? 28                            \
   : (_) == 'd' ? 29                            \
   : (_) == 'e' ? 30                            \
   : (_) == 'f' ? 31                            \
   : (_) == 'g' ? 32                            \
   : (_) == 'h' ? 33                            \
   : (_) == 'i' ? 34                            \
   : (_) == 'j' ? 35                            \
   : (_) == 'k' ? 36                            \
   : (_) == 'l' ? 37                            \
   : (_) == 'm' ? 38                            \
   : (_) == 'n' ? 39                            \
   : (_) == 'o' ? 40                            \
   : (_) == 'p' ? 41                            \
   : (_) == 'q' ? 42                            \
   : (_) == 'r' ? 43                            \
   : (_) == 's' ? 44                            \
   : (_) == 't' ? 45                            \
   : (_) == 'u' ? 46                            \
   : (_) == 'v' ? 47                            \
   : (_) == 'w' ? 48                            \
   : (_) == 'x' ? 49                            \
   : (_) == 'y' ? 50                            \
   : (_) == 'z' ? 51                            \
   : (_) == '0' ? 52                            \
   : (_) == '1' ? 53                            \
   : (_) == '2' ? 54                            \
   : (_) == '3' ? 55                            \
   : (_) == '4' ? 56                            \
   : (_) == '5' ? 57                            \
   : (_) == '6' ? 58                            \
   : (_) == '7' ? 59                            \
   : (_) == '8' ? 60                            \
   : (_) == '9' ? 61                            \
   : (_) == '_' ? 62                            \
   : (_) == ':' ? 63                            \
   : (_) == '\0'? 64                            \
   : 128)

static const char dtable_rfc[0x100] = {
  db64_rfc (0), db64_rfc (1), db64_rfc (2), db64_rfc (3),
  db64_rfc (4), db64_rfc (5), db64_rfc (6), db64_rfc (7),
  db64_rfc (8), db64_rfc (9), db64_rfc (10), db64_rfc (11),
  db64_rfc (12), db64_rfc (13), db64_rfc (14), db64_rfc (15),
  db64_rfc (16), db64_rfc (17), db64_rfc (18), db64_rfc (19),
  db64_rfc (20), db64_rfc (21), db64_rfc (22), db64_rfc (23),
  db64_rfc (24), db64_rfc (25), db64_rfc (26), db64_rfc (27),
  db64_rfc (28), db64_rfc (29), db64_rfc (30), db64_rfc (31),
  db64_rfc (32), db64_rfc (33), db64_rfc (34), db64_rfc (35),
  db64_rfc (36), db64_rfc (37), db64_rfc (38), db64_rfc (39),
  db64_rfc (40), db64_rfc (41), db64_rfc (42), db64_rfc (43),
  db64_rfc (44), db64_rfc (45), db64_rfc (46), db64_rfc (47),
  db64_rfc (48), db64_rfc (49), db64_rfc (50), db64_rfc (51),
  db64_rfc (52), db64_rfc (53), db64_rfc (54), db64_rfc (55),
  db64_rfc (56), db64_rfc (57), db64_rfc (58), db64_rfc (59),
  db64_rfc (60), db64_rfc (61), db64_rfc (62), db64_rfc (63),
  db64_rfc (64), db64_rfc (65), db64_rfc (66), db64_rfc (67),
  db64_rfc (68), db64_rfc (69), db64_rfc (70), db64_rfc (71),
  db64_rfc (72), db64_rfc (73), db64_rfc (74), db64_rfc (75),
  db64_rfc (76), db64_rfc (77), db64_rfc (78), db64_rfc (79),
  db64_rfc (80), db64_rfc (81), db64_rfc (82), db64_rfc (83),
  db64_rfc (84), db64_rfc (85), db64_rfc (86), db64_rfc (87),
  db64_rfc (88), db64_rfc (89), db64_rfc (90), db64_rfc (91),
  db64_rfc (92), db64_rfc (93), db64_rfc (94), db64_rfc (95),
  db64_rfc (96), db64_rfc (97), db64_rfc (98), db64_rfc (99),
  db64_rfc (100), db64_rfc (101), db64_rfc (102), db64_rfc (103),
  db64_rfc (104), db64_rfc (105), db64_rfc (106), db64_rfc (107),
  db64_rfc (108), db64_rfc (109), db64_rfc (110), db64_rfc (111),
  db64_rfc (112), db64_rfc (113), db64_rfc (114), db64_rfc (115),
  db64_rfc (116), db64_rfc (117), db64_rfc (118), db64_rfc (119),
  db64_rfc (120), db64_rfc (121), db64_rfc (122), db64_rfc (123),
  db64_rfc (124), db64_rfc (125), db64_rfc (126), db64_rfc (127),
  db64_rfc (128), db64_rfc (129), db64_rfc (130), db64_rfc (131),
  db64_rfc (132), db64_rfc (133), db64_rfc (134), db64_rfc (135),
  db64_rfc (136), db64_rfc (137), db64_rfc (138), db64_rfc (139),
  db64_rfc (140), db64_rfc (141), db64_rfc (142), db64_rfc (143),
  db64_rfc (144), db64_rfc (145), db64_rfc (146), db64_rfc (147),
  db64_rfc (148), db64_rfc (149), db64_rfc (150), db64_rfc (151),
  db64_rfc (152), db64_rfc (153), db64_rfc (154), db64_rfc (155),
  db64_rfc (156), db64_rfc (157), db64_rfc (158), db64_rfc (159),
  db64_rfc (160), db64_rfc (161), db64_rfc (162), db64_rfc (163),
  db64_rfc (164), db64_rfc (165), db64_rfc (166), db64_rfc (167),
  db64_rfc (168), db64_rfc (169), db64_rfc (170), db64_rfc (171),
  db64_rfc (172), db64_rfc (173), db64_rfc (174), db64_rfc (175),
  db64_rfc (176), db64_rfc (177), db64_rfc (178), db64_rfc (179),
  db64_rfc (180), db64_rfc (181), db64_rfc (182), db64_rfc (183),
  db64_rfc (184), db64_rfc (185), db64_rfc (186), db64_rfc (187),
  db64_rfc (188), db64_rfc (189), db64_rfc (190), db64_rfc (191),
  db64_rfc (192), db64_rfc (193), db64_rfc (194), db64_rfc (195),
  db64_rfc (196), db64_rfc (197), db64_rfc (198), db64_rfc (199),
  db64_rfc (200), db64_rfc (201), db64_rfc (202), db64_rfc (203),
  db64_rfc (204), db64_rfc (205), db64_rfc (206), db64_rfc (207),
  db64_rfc (208), db64_rfc (209), db64_rfc (210), db64_rfc (211),
  db64_rfc (212), db64_rfc (213), db64_rfc (214), db64_rfc (215),
  db64_rfc (216), db64_rfc (217), db64_rfc (218), db64_rfc (219),
  db64_rfc (220), db64_rfc (221), db64_rfc (222), db64_rfc (223),
  db64_rfc (224), db64_rfc (225), db64_rfc (226), db64_rfc (227),
  db64_rfc (228), db64_rfc (229), db64_rfc (230), db64_rfc (231),
  db64_rfc (232), db64_rfc (233), db64_rfc (234), db64_rfc (235),
  db64_rfc (236), db64_rfc (237), db64_rfc (238), db64_rfc (239),
  db64_rfc (240), db64_rfc (241), db64_rfc (242), db64_rfc (243),
  db64_rfc (244), db64_rfc (245), db64_rfc (246), db64_rfc (247),
  db64_rfc (248), db64_rfc (249), db64_rfc (250), db64_rfc (251),
  db64_rfc (252), db64_rfc (253), db64_rfc (254), db64_rfc (255)
};

static const char dtable_url[0x100] = {
  db64_url (0), db64_url (1), db64_url (2), db64_url (3),
  db64_url (4), db64_url (5), db64_url (6), db64_url (7),
  db64_url (8), db64_url (9), db64_url (10), db64_url (11),
  db64_url (12), db64_url (13), db64_url (14), db64_url (15),
  db64_url (16), db64_url (17), db64_url (18), db64_url (19),
  db64_url (20), db64_url (21), db64_url (22), db64_url (23),
  db64_url (24), db64_url (25), db64_url (26), db64_url (27),
  db64_url (28), db64_url (29), db64_url (30), db64_url (31),
  db64_url (32), db64_url (33), db64_url (34), db64_url (35),
  db64_url (36), db64_url (37), db64_url (38), db64_url (39),
  db64_url (40), db64_url (41), db64_url (42), db64_url (43),
  db64_url (44), db64_url (45), db64_url (46), db64_url (47),
  db64_url (48), db64_url (49), db64_url (50), db64_url (51),
  db64_url (52), db64_url (53), db64_url (54), db64_url (55),
  db64_url (56), db64_url (57), db64_url (58), db64_url (59),
  db64_url (60), db64_url (61), db64_url (62), db64_url (63),
  db64_url (64), db64_url (65), db64_url (66), db64_url (67),
  db64_url (68), db64_url (69), db64_url (70), db64_url (71),
  db64_url (72), db64_url (73), db64_url (74), db64_url (75),
  db64_url (76), db64_url (77), db64_url (78), db64_url (79),
  db64_url (80), db64_url (81), db64_url (82), db64_url (83),
  db64_url (84), db64_url (85), db64_url (86), db64_url (87),
  db64_url (88), db64_url (89), db64_url (90), db64_url (91),
  db64_url (92), db64_url (93), db64_url (94), db64_url (95),
  db64_url (96), db64_url (97), db64_url (98), db64_url (99),
  db64_url (100), db64_url (101), db64_url (102), db64_url (103),
  db64_url (104), db64_url (105), db64_url (106), db64_url (107),
  db64_url (108), db64_url (109), db64_url (110), db64_url (111),
  db64_url (112), db64_url (113), db64_url (114), db64_url (115),
  db64_url (116), db64_url (117), db64_url (118), db64_url (119),
  db64_url (120), db64_url (121), db64_url (122), db64_url (123),
  db64_url (124), db64_url (125), db64_url (126), db64_url (127),
  db64_url (128), db64_url (129), db64_url (130), db64_url (131),
  db64_url (132), db64_url (133), db64_url (134), db64_url (135),
  db64_url (136), db64_url (137), db64_url (138), db64_url (139),
  db64_url (140), db64_url (141), db64_url (142), db64_url (143),
  db64_url (144), db64_url (145), db64_url (146), db64_url (147),
  db64_url (148), db64_url (149), db64_url (150), db64_url (151),
  db64_url (152), db64_url (153), db64_url (154), db64_url (155),
  db64_url (156), db64_url (157), db64_url (158), db64_url (159),
  db64_url (160), db64_url (161), db64_url (162), db64_url (163),
  db64_url (164), db64_url (165), db64_url (166), db64_url (167),
  db64_url (168), db64_url (169), db64_url (170), db64_url (171),
  db64_url (172), db64_url (173), db64_url (174), db64_url (175),
  db64_url (176), db64_url (177), db64_url (178), db64_url (179),
  db64_url (180), db64_url (181), db64_url (182), db64_url (183),
  db64_url (184), db64_url (185), db64_url (186), db64_url (187),
  db64_url (188), db64_url (189), db64_url (190), db64_url (191),
  db64_url (192), db64_url (193), db64_url (194), db64_url (195),
  db64_url (196), db64_url (197), db64_url (198), db64_url (199),
  db64_url (200), db64_url (201), db64_url (202), db64_url (203),
  db64_url (204), db64_url (205), db64_url (206), db64_url (207),
  db64_url (208), db64_url (209), db64_url (210), db64_url (211),
  db64_url (212), db64_url (213), db64_url (214), db64_url (215),
  db64_url (216), db64_url (217), db64_url (218), db64_url (219),
  db64_url (220), db64_url (221), db64_url (222), db64_url (223),
  db64_url (224), db64_url (225), db64_url (226), db64_url (227),
  db64_url (228), db64_url (229), db64_url (230), db64_url (231),
  db64_url (232), db64_url (233), db64_url (234), db64_url (235),
  db64_url (236), db64_url (237), db64_url (238), db64_url (239),
  db64_url (240), db64_url (241), db64_url (242), db64_url (243),
  db64_url (244), db64_url (245), db64_url (246), db64_url (247),
  db64_url (248), db64_url (249), db64_url (250), db64_url (251),
  db64_url (252), db64_url (253), db64_url (254), db64_url (255)
};

static const char dtable_xmlt[0x100] = {
  db64_xmlt (0), db64_xmlt (1), db64_xmlt (2), db64_xmlt (3),
  db64_xmlt (4), db64_xmlt (5), db64_xmlt (6), db64_xmlt (7),
  db64_xmlt (8), db64_xmlt (9), db64_xmlt (10), db64_xmlt (11),
  db64_xmlt (12), db64_xmlt (13), db64_xmlt (14), db64_xmlt (15),
  db64_xmlt (16), db64_xmlt (17), db64_xmlt (18), db64_xmlt (19),
  db64_xmlt (20), db64_xmlt (21), db64_xmlt (22), db64_xmlt (23),
  db64_xmlt (24), db64_xmlt (25), db64_xmlt (26), db64_xmlt (27),
  db64_xmlt (28), db64_xmlt (29), db64_xmlt (30), db64_xmlt (31),
  db64_xmlt (32), db64_xmlt (33), db64_xmlt (34), db64_xmlt (35),
  db64_xmlt (36), db64_xmlt (37), db64_xmlt (38), db64_xmlt (39),
  db64_xmlt (40), db64_xmlt (41), db64_xmlt (42), db64_xmlt (43),
  db64_xmlt (44), db64_xmlt (45), db64_xmlt (46), db64_xmlt (47),
  db64_xmlt (48), db64_xmlt (49), db64_xmlt (50), db64_xmlt (51),
  db64_xmlt (52), db64_xmlt (53), db64_xmlt (54), db64_xmlt (55),
  db64_xmlt (56), db64_xmlt (57), db64_xmlt (58), db64_xmlt (59),
  db64_xmlt (60), db64_xmlt (61), db64_xmlt (62), db64_xmlt (63),
  db64_xmlt (64), db64_xmlt (65), db64_xmlt (66), db64_xmlt (67),
  db64_xmlt (68), db64_xmlt (69), db64_xmlt (70), db64_xmlt (71),
  db64_xmlt (72), db64_xmlt (73), db64_xmlt (74), db64_xmlt (75),
  db64_xmlt (76), db64_xmlt (77), db64_xmlt (78), db64_xmlt (79),
  db64_xmlt (80), db64_xmlt (81), db64_xmlt (82), db64_xmlt (83),
  db64_xmlt (84), db64_xmlt (85), db64_xmlt (86), db64_xmlt (87),
  db64_xmlt (88), db64_xmlt (89), db64_xmlt (90), db64_xmlt (91),
  db64_xmlt (92), db64_xmlt (93), db64_xmlt (94), db64_xmlt (95),
  db64_xmlt (96), db64_xmlt (97), db64_xmlt (98), db64_xmlt (99),
  db64_xmlt (100), db64_xmlt (101), db64_xmlt (102), db64_xmlt (103),
  db64_xmlt (104), db64_xmlt (105), db64_xmlt (106), db64_xmlt (107),
  db64_xmlt (108), db64_xmlt (109), db64_xmlt (110), db64_xmlt (111),
  db64_xmlt (112), db64_xmlt (113), db64_xmlt (114), db64_xmlt (115),
  db64_xmlt (116), db64_xmlt (117), db64_xmlt (118), db64_xmlt (119),
  db64_xmlt (120), db64_xmlt (121), db64_xmlt (122), db64_xmlt (123),
  db64_xmlt (124), db64_xmlt (125), db64_xmlt (126), db64_xmlt (127),
  db64_xmlt (128), db64_xmlt (129), db64_xmlt (130), db64_xmlt (131),
  db64_xmlt (132), db64_xmlt (133), db64_xmlt (134), db64_xmlt (135),
  db64_xmlt (136), db64_xmlt (137), db64_xmlt (138), db64_xmlt (139),
  db64_xmlt (140), db64_xmlt (141), db64_xmlt (142), db64_xmlt (143),
  db64_xmlt (144), db64_xmlt (145), db64_xmlt (146), db64_xmlt (147),
  db64_xmlt (148), db64_xmlt (149), db64_xmlt (150), db64_xmlt (151),
  db64_xmlt (152), db64_xmlt (153), db64_xmlt (154), db64_xmlt (155),
  db64_xmlt (156), db64_xmlt (157), db64_xmlt (158), db64_xmlt (159),
  db64_xmlt (160), db64_xmlt (161), db64_xmlt (162), db64_xmlt (163),
  db64_xmlt (164), db64_xmlt (165), db64_xmlt (166), db64_xmlt (167),
  db64_xmlt (168), db64_xmlt (169), db64_xmlt (170), db64_xmlt (171),
  db64_xmlt (172), db64_xmlt (173), db64_xmlt (174), db64_xmlt (175),
  db64_xmlt (176), db64_xmlt (177), db64_xmlt (178), db64_xmlt (179),
  db64_xmlt (180), db64_xmlt (181), db64_xmlt (182), db64_xmlt (183),
  db64_xmlt (184), db64_xmlt (185), db64_xmlt (186), db64_xmlt (187),
  db64_xmlt (188), db64_xmlt (189), db64_xmlt (190), db64_xmlt (191),
  db64_xmlt (192), db64_xmlt (193), db64_xmlt (194), db64_xmlt (195),
  db64_xmlt (196), db64_xmlt (197), db64_xmlt (198), db64_xmlt (199),
  db64_xmlt (200), db64_xmlt (201), db64_xmlt (202), db64_xmlt (203),
  db64_xmlt (204), db64_xmlt (205), db64_xmlt (206), db64_xmlt (207),
  db64_xmlt (208), db64_xmlt (209), db64_xmlt (210), db64_xmlt (211),
  db64_xmlt (212), db64_xmlt (213), db64_xmlt (214), db64_xmlt (215),
  db64_xmlt (216), db64_xmlt (217), db64_xmlt (218), db64_xmlt (219),
  db64_xmlt (220), db64_xmlt (221), db64_xmlt (222), db64_xmlt (223),
  db64_xmlt (224), db64_xmlt (225), db64_xmlt (226), db64_xmlt (227),
  db64_xmlt (228), db64_xmlt (229), db64_xmlt (230), db64_xmlt (231),
  db64_xmlt (232), db64_xmlt (233), db64_xmlt (234), db64_xmlt (235),
  db64_xmlt (236), db64_xmlt (237), db64_xmlt (238), db64_xmlt (239),
  db64_xmlt (240), db64_xmlt (241), db64_xmlt (242), db64_xmlt (243),
  db64_xmlt (244), db64_xmlt (245), db64_xmlt (246), db64_xmlt (247),
  db64_xmlt (248), db64_xmlt (249), db64_xmlt (250), db64_xmlt (251),
  db64_xmlt (252), db64_xmlt (253), db64_xmlt (254), db64_xmlt (255)
};


static const char dtable_xmli[0x100] = {
  db64_xmli (0), db64_xmli (1), db64_xmli (2), db64_xmli (3),
  db64_xmli (4), db64_xmli (5), db64_xmli (6), db64_xmli (7),
  db64_xmli (8), db64_xmli (9), db64_xmli (10), db64_xmli (11),
  db64_xmli (12), db64_xmli (13), db64_xmli (14), db64_xmli (15),
  db64_xmli (16), db64_xmli (17), db64_xmli (18), db64_xmli (19),
  db64_xmli (20), db64_xmli (21), db64_xmli (22), db64_xmli (23),
  db64_xmli (24), db64_xmli (25), db64_xmli (26), db64_xmli (27),
  db64_xmli (28), db64_xmli (29), db64_xmli (30), db64_xmli (31),
  db64_xmli (32), db64_xmli (33), db64_xmli (34), db64_xmli (35),
  db64_xmli (36), db64_xmli (37), db64_xmli (38), db64_xmli (39),
  db64_xmli (40), db64_xmli (41), db64_xmli (42), db64_xmli (43),
  db64_xmli (44), db64_xmli (45), db64_xmli (46), db64_xmli (47),
  db64_xmli (48), db64_xmli (49), db64_xmli (50), db64_xmli (51),
  db64_xmli (52), db64_xmli (53), db64_xmli (54), db64_xmli (55),
  db64_xmli (56), db64_xmli (57), db64_xmli (58), db64_xmli (59),
  db64_xmli (60), db64_xmli (61), db64_xmli (62), db64_xmli (63),
  db64_xmli (64), db64_xmli (65), db64_xmli (66), db64_xmli (67),
  db64_xmli (68), db64_xmli (69), db64_xmli (70), db64_xmli (71),
  db64_xmli (72), db64_xmli (73), db64_xmli (74), db64_xmli (75),
  db64_xmli (76), db64_xmli (77), db64_xmli (78), db64_xmli (79),
  db64_xmli (80), db64_xmli (81), db64_xmli (82), db64_xmli (83),
  db64_xmli (84), db64_xmli (85), db64_xmli (86), db64_xmli (87),
  db64_xmli (88), db64_xmli (89), db64_xmli (90), db64_xmli (91),
  db64_xmli (92), db64_xmli (93), db64_xmli (94), db64_xmli (95),
  db64_xmli (96), db64_xmli (97), db64_xmli (98), db64_xmli (99),
  db64_xmli (100), db64_xmli (101), db64_xmli (102), db64_xmli (103),
  db64_xmli (104), db64_xmli (105), db64_xmli (106), db64_xmli (107),
  db64_xmli (108), db64_xmli (109), db64_xmli (110), db64_xmli (111),
  db64_xmli (112), db64_xmli (113), db64_xmli (114), db64_xmli (115),
  db64_xmli (116), db64_xmli (117), db64_xmli (118), db64_xmli (119),
  db64_xmli (120), db64_xmli (121), db64_xmli (122), db64_xmli (123),
  db64_xmli (124), db64_xmli (125), db64_xmli (126), db64_xmli (127),
  db64_xmli (128), db64_xmli (129), db64_xmli (130), db64_xmli (131),
  db64_xmli (132), db64_xmli (133), db64_xmli (134), db64_xmli (135),
  db64_xmli (136), db64_xmli (137), db64_xmli (138), db64_xmli (139),
  db64_xmli (140), db64_xmli (141), db64_xmli (142), db64_xmli (143),
  db64_xmli (144), db64_xmli (145), db64_xmli (146), db64_xmli (147),
  db64_xmli (148), db64_xmli (149), db64_xmli (150), db64_xmli (151),
  db64_xmli (152), db64_xmli (153), db64_xmli (154), db64_xmli (155),
  db64_xmli (156), db64_xmli (157), db64_xmli (158), db64_xmli (159),
  db64_xmli (160), db64_xmli (161), db64_xmli (162), db64_xmli (163),
  db64_xmli (164), db64_xmli (165), db64_xmli (166), db64_xmli (167),
  db64_xmli (168), db64_xmli (169), db64_xmli (170), db64_xmli (171),
  db64_xmli (172), db64_xmli (173), db64_xmli (174), db64_xmli (175),
  db64_xmli (176), db64_xmli (177), db64_xmli (178), db64_xmli (179),
  db64_xmli (180), db64_xmli (181), db64_xmli (182), db64_xmli (183),
  db64_xmli (184), db64_xmli (185), db64_xmli (186), db64_xmli (187),
  db64_xmli (188), db64_xmli (189), db64_xmli (190), db64_xmli (191),
  db64_xmli (192), db64_xmli (193), db64_xmli (194), db64_xmli (195),
  db64_xmli (196), db64_xmli (197), db64_xmli (198), db64_xmli (199),
  db64_xmli (200), db64_xmli (201), db64_xmli (202), db64_xmli (203),
  db64_xmli (204), db64_xmli (205), db64_xmli (206), db64_xmli (207),
  db64_xmli (208), db64_xmli (209), db64_xmli (210), db64_xmli (211),
  db64_xmli (212), db64_xmli (213), db64_xmli (214), db64_xmli (215),
  db64_xmli (216), db64_xmli (217), db64_xmli (218), db64_xmli (219),
  db64_xmli (220), db64_xmli (221), db64_xmli (222), db64_xmli (223),
  db64_xmli (224), db64_xmli (225), db64_xmli (226), db64_xmli (227),
  db64_xmli (228), db64_xmli (229), db64_xmli (230), db64_xmli (231),
  db64_xmli (232), db64_xmli (233), db64_xmli (234), db64_xmli (235),
  db64_xmli (236), db64_xmli (237), db64_xmli (238), db64_xmli (239),
  db64_xmli (240), db64_xmli (241), db64_xmli (242), db64_xmli (243),
  db64_xmli (244), db64_xmli (245), db64_xmli (246), db64_xmli (247),
  db64_xmli (248), db64_xmli (249), db64_xmli (250), db64_xmli (251),
  db64_xmli (252), db64_xmli (253), db64_xmli (254), db64_xmli (255)
};


struct tables {
    const char *table_name;
    const char *etable_ptr;
    const char *dtable_ptr;
};

static const tables b64_tables[] = {
    {"rfc", etable_rfc, dtable_rfc},
    {"url", etable_url, dtable_url},
    {"xmlt", etable_xmlt, dtable_xmlt},
    {"xmli", etable_xmli, dtable_xmli},
    {0,0,0}
};

#endif	/* BASE64LIB_H */

