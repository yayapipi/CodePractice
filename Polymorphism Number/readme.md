#Polymorphism
--------------
Number is a class contain 1 digit number;
TwoDigitNumber is derivative the class Number;
ThreeDigitNumber then derivative TwoDigitNumber class;

TestNumber class can generate an pointer of array to store random class of Number/TwoDigit/ThreeDigitNumber,
which is the idea of polymorphism.Then the dynamic_cast is used to detect the class type in that array.
