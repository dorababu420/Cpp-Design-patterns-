/* Abstract Factory Design Pattern */
#include <iostream.h>
class Shape {
   public:
        Shape(){
	      id_ = total_;
	    }
		vitual void draw() = 0; //pure virtual function
	protected:
	    int id_;
		static int total_;
}
int Shape::total_ = 0;
class  Circle:public Shape {
    public:
	    void draw(){
		    cout << "Circile" << id_ << :draw <<endl;
		}
};
class Square:public Shape {
    public:
	    void draw(){
		    cout << "Square" << id_ << ":Draw" <<endl;
		}
};
class Ellipse:public Shape {
    public:
        void draw(){
            cout << "Ellipse" << id_ << "Draw" <<endl;
        }
};
class Rectangle:public Shape {
    public:
        void draw(){
            cout << "Rectangle" << id_ << "Draw" <<endl;
        }
};
class Factory {
    public:
      virtual Shape* createCurveShapeInstance() = 0;
      virtual Shape* createStraitSahpeInstance() = 0;
};
class SimpleFactoryInstance:public Factory {
    public:
        Shape* createCurvedShapeInstance(){
            return new Circle;
        }
		Shape* createStraightShapeInstance(){
		return new Square;
		}
};
class RubstFactoryInstance:public Factory{
    public:
       Shape* createCurvedShapeInstance(){
        return new Ellipse;
       }
       Shape* createStraightShapeInstance(){
        return new Rectangle;
       }
};

int main()
{
  #ifdef SIMPLE
       Factory* factory = new SimpleFactoryInstance;
  #elif ROBUST
       Factory* factory = new RubustFactoryInsyance;
  #endif
   Shape* shape[3];
   shape[0] = factory->createCurvedShapeInstance();
   shape[1] = factory->createStraightSahpeInstance();
   shape[2] = factory->createCurvedShapeInstance();
   for(int i = 0; i < 3; i++){
       shape[i]->draw();
    }
}	   
		
		
		