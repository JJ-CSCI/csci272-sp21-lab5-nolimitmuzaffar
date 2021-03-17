//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{

protected: //it can't be a private, because private var can't be accessed from inheritance
float real_value = 0; //the numbers passed are float numbers
  public:
    float GetReal(){//to get the value
    return real_value;
  }
  Real(float one){//constructor to store 1 real coefficient 
    real_value = one;
  }

     Real operator*(const float&xyz){
     real_value=real_value*xyz;
     return *this;//returning a reference to the object
  }
};
//This existing class Real is the base class, and the new class is going to be the derived class

class Complex: public Real{
  protected: //because private varriables can't be accessed from inheritance 
  float complex_value = 0;  //the numbers passed are float numbers
  public:
  float GetImaginary(){//accesor  method
     return complex_value;
  }
    Complex(float one, float two):Real(one){// the constructor. complex class is being derived
    complex_value = two;
      }
  Complex operator*(const float&ABC){
    real_value= real_value*ABC;
    complex_value=complex_value* ABC;
  //this means pointer to the object
    return *this;
  }
};
//this is derived class 
class Surreal: public Complex{
  float surreal_value= 0;   //the numbers passed are float numbers
   public:
   float GetSurreal(){//accesor function to return third value
     return surreal_value;
  }
//constructor
   Surreal(float one, float two, float three):Complex(one, two){
     surreal_value = three;
    }
  //note : in c++ a class can inherit from more than one class 

  Surreal operator*(const float&ABC){
    real_value= real_value*ABC;
    complex_value=complex_value*ABC;
    surreal_value=surreal_value*ABC;
//return a reference to the object
    return *this; 
  }


};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
