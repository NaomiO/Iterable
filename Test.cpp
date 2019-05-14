//
// Created by amir on 5/9/19.
//

#include <iostream>
#include <string>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace std;
using namespace itertools;

int main(){
    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {

        //Our tests
        int a=1,b=10,c=21,d=35,e=2345,f=10000,g=10014;
        double w=2.5,x=10.3,y=24.4,z=7878.5,p=7883.7;
        char ch1='a',ch2='z',ch3='e',ch4='P',ch5='V',ch6='0',ch7='~';

 		
                testcase.setname("range-tests")
                .CHECK_OUTPUT(range(1,10),"1 2 3 4 5 6 7 8 9")
               /* .CHECK_OUTPUT(range(b,c),"10 11 12 13 14 15 16 17 18 19 20")
                .CHECK_OUTPUT(range(c,d),"21 22 23 24 25 26 27 28 29 30 31 32 33 34")
                .CHECK_OUTPUT(range(f,g),"10000 10001 10002 10003 10004 10005 10006 10007 10008 10009 10010 10011 10012 10013")

                .CHECK_OUTPUT(range(w,x),"2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5")
                .CHECK_OUTPUT(range(x,y),"10.3 11.3 12.3 13.3 14.3 15.3 16.3 17.3 18.3 19.3 20.3 21.3 22.3 23.3 24.3")
                .CHECK_OUTPUT(range(z,p),"7878.5 7879.5 7880.5 7881.5 7882.5 7883.5")

                .CHECK_OUTPUT(range(ch1,ch3),"a b c d")
                .CHECK_OUTPUT(range(ch4,ch5),"P Q R S T U")

                .CHECK_OK(range(a,d))
                .CHECK_OK(range(a,e))
                .CHECK_OK(range(d,f))
                .CHECK_OK(range(e,f))
                .CHECK_OK(range(a,f))
                .CHECK_OK(range(d,g))
                .CHECK_OK(range(a,g))

                .CHECK_OK(range(w,y))
                .CHECK_OK(range(w,z))
                .CHECK_OK(range(x,p))
                .CHECK_OK(range(w,p))

                .CHECK_OK(range(ch1,ch2))
                .CHECK_OK(range(ch6,ch7))

                .CHECK_THROWS(range(b,a))//a<b
                .CHECK_THROWS(range(d,b))//b<d
                .CHECK_THROWS(range(e,b))//b<e
                .CHECK_THROWS(range(f,a))//a<f
                .CHECK_THROWS(range(g,a))//a<g
                .CHECK_THROWS(range(a,w))//int!=double
                .CHECK_THROWS(range(b,z))//int!=double
                .CHECK_THROWS(range(w,g))//double!=int
                .CHECK_THROWS(range(ch3,ch1))//a<e
                .CHECK_THROWS(range(ch3,ch4))//P<e in ASCII
                .CHECK_THROWS(range(ch7,ch2))//z < ~ in ASCII
                .CHECK_THROWS(range(ch3,c))//char!=int
                .CHECK_THROWS(range(w,ch4))//double!=char
                .CHECK_THROWS(range(f,ch7))//int!=char

                ;

        testcase.setname("operator != tests")
                .CHECK_EQUAL(a != w , true)//int!=double
                .CHECK_EQUAL(a != b , false)//int==int
                .CHECK_EQUAL(a != f , false)//int==int
                .CHECK_EQUAL(c != ch3 , true)//int!=char
                .CHECK_EQUAL(ch1 != ch2 , false)//char==char
                .CHECK_EQUAL(x != b , true)//double!=int
                .CHECK_EQUAL(y != z , false)//double==double

                ;
///////////////////////////////////////////////////////////////////////////////////

        testcase.setname("chain-tests")
                .CHECK_OUTPUT(chain(range(1,4),range(5,9)),"1 2 3 5 6 7 8")
                .CHECK_OUTPUT(chain(range('a','d'),string("hello")),"a b c h e l l o")
                .CHECK_OUTPUT(chain(range('R','U'),range('r','u')),"R S T r s t")
                .CHECK_OUTPUT(chain(string("kill"),string("me")),"k i l l m e")
                .CHECK_OUTPUT(chain(range(5.1,8.9),range('g','k')),"5.1 6.1 7.1 8.1 g h i j")
                .CHECK_OUTPUT(chain(range(-5,0),range('0','6')),"-5 -4 -3 -2 -1 0 1 2 3 4 5")

                .CHECK_OK(chain(range(5,500),range(8.5,11.5)))
                .CHECK_OK(chain(range('A','P'),range(45,56)))
                .CHECK_OK(chain(range('0','9'),range(0,9)))

                .CHECK_THROWS(chain(range('f','a'),range(1,5)))//a<f
                .CHECK_THROWS(chain(range(5.2,7.0),range(7.0,5.2)))//5.2<7.0
                .CHECK_THROWS(chain(string("Error"),range(5,-5)))//-5<5

                ;
/////////////////////////////////////////////////////////////////////////////
        testcase.setname("zip-tests")

                .CHECK_OUTPUT(zip(range(1,6),string("hello")),"1,h 2,e 3,l 4,l 5,o")
                .CHECK_OUTPUT(zip(range(12,16),range(5.2,9.1)),"12,5.2 13,6.2 14,7.2 15,8.2")
                .CHECK_OUTPUT(zip(range('R','U'),range(-1,2)),"R,-1 S,0 T,1")
                .CHECK_OUTPUT(zip(range(':','?'),range(1,6),":,1 ;,2 <,3 =,4 >,5")
                .CHECK_OUTPUT(zip(range(-9.3,-5.4),string("????")),"-9.3,? -8.3,? -7.3,? -6.3,?")
                .CHECK_OUTPUT(zip(range(22222,22229),range('w','~')),"22222,w 22223,x 22224,y 22225,z 22226,{ 22227,| 22228,}")
                .CHECK_OUTPUT(zip(string("boy"),string("men")),"b,m o,e y,n")
                .CHECK_OUTPUT(zip(string("RD"),string("22")),"R,2 D,2")
                .CHECK_OUTPUT(zip(string("ttttt"),range(-5,0)),"t,-5 t,-4 t,-3 t,-2 t,-1")
                .CHECK_OUTPUT(zip(range('a','j'),range(1,10)),"a,1 b,2 c,3 d,4 e,5 f,6 g,7 h,8 i,9")

                ;
//////////////////////////////////////////////////////////////////////////////

        testcase.setname("product-tests")
                .CHECK_OUTPUT(product(range(1,4),string("helo")),"1,h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o")
                .CHECK_OUTPUT(product(range(8,12),range(9999,10000)),"8,9999 9,9999 10,9999 11,9999")
                .CHECK_OUTPUT(product(range('h','k'),range(6.6,8.2)),"h,6.6 h,7.6 i,6.6 i,7.6 j,6.6 j,7.6")
                .CHECK_OUTPUT(product(string("end"),string("game")),"e,g e,a e,m e,e n,g n,a n,m n,e d,g d,a d,m d,e")
                .CHECK_OUTPUT(product(range('d','f'),range('P','R')),"d,P d,Q e,P e,Q")
                .CHECK_OUTPUT(product(range('?','A'),range(19,21)),"?,19 ?,20 @,19 @,20")
                .CHECK_OUTPUT(product(range(2.5,4.7),string("no")),"2.5,n 2.5,o 3.5,n 3.5,o 4.5,n 4.5,o")
                .CHECK_OUTPUT(product(string("end"),range(84,89)),"e,84 e,85 e,86 e,87 e,88 n,84 n,85 n,86 n,87 n,88 d,84 d,85 d,86 d,87 d,88")
                .CHECK_OUTPUT(product(range('#','&'),range(1.9,2.1)),"#,1.9 $,1.9 %,1.9")
                .CHECK_OUTPUT(product(range(555,559),string("why")),"555,w 555,h 555,y 556,w 556,h 556,y 557,w 557,h 557,y 558,w 558,h 558,y")

                ;
/////////////////////////////////////////////////////////////////////////////////

        testcase.setname("powerset")
                .CHECK_OUTPUT(powerset(string("abc")),"{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c}")
                .CHECK_OUTPUT(powerset(range(x,z)),"{},{x},{z},{x,z}")
                .CHECK_OUTPUT(powerset(range('+','.')),"{},{+},{,},{+,,},{-},{+,-},{,,-},{+,,,-}")
                .CHECK_OUTPUT(powerset(range(12,16)),"{},{12},{13},{12,13},{14},{12,14},{13,14},{15},{12,15},{13,15},{14,15},{12,13,14},{12,13,15},{12,14,15},{13,14,15},{12,13,14,15}")
                .CHECK_OUTPUT(powerset(range(5.7,8.2)),"{},{5.7},{6.7},{5.7,6.7},{7.7},{5.7,7.7},{6.7,7.7},{5.7,6.7,7.7}")
                .CHECK_OUTPUT(powerset(string("?2gQ")),"{},{?},{2},{?,2},{g},{?,g},{2,g},{Q},{?,Q},{2,Q},{g,Q},{?,2,g},{?,2,Q},{?,g,Q},{2,g,Q},{?,2,g,Q}")
                .CHECK_OUTPUT(powerset(range(1,3)),"{},{1},{2},{1,2}")
                .CHECK_OUTPUT(powerset(string("a")),"{},{a}")
                .CHECK_OUTPUT(powerset(range(1,6)),"{},{1},{2},{1,2},{3},{1,3},{2,3},{4},{1,4},{2,4},{3,4},{5},{1,5},{2,5},{3,5},{4,5},{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},{1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5},{1,2,3,4},{1,2,3,5},{1,2,4,5},{1,3,4,5},{2,3,4,5},{1,2,3,4,5}")

                .CHECK_THROWS(powerset(string("11111")))//Repetitions*/
                ;

/////////////////////////////////////////////////////////////////////////////////
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }

    cout <<  "* Grade: " << grade << " *" << endl;
    return grade;
}
