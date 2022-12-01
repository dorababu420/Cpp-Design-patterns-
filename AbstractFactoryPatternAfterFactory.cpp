/*AbstractFactoryDesignPattern creating factory concurent classes object with basefactory interface */
#include <iostream>
using namespace std;
class widget
{
    public:
		virtual void draw() = 0;
};
#ifdef LINUX
class LinuxButton:public widget
{
	public:
		void draw()
		{
			cout << "LinuxButton\n" << endl;
		}
};
class LinuxMenu:public widget
{
	public:
		void draw()
		{
			cout << "LinuxMenu\n" << endl;
		}
};
#else
class WindowsButton:public widget
{
	public:
		void draw(){
			cout << "WindowsButton \n" << endl;
		}
};
class WindowsMenu:public widget
{
	public:
		void draw()
		{
			cout << "WindowsMenu \n" <<endl;
		}
};
#endif
class Factory
{
	public:
		virtual widget* Create_Button() = 0;
		virtual widget* Create_Menu() = 0;
};
class LinuxFactory:public Factory
{
	public:
	widget* create_Button(){
	 return new LinuxButton;
	 }
	 widget* create_Menu(){
	 return new LinuxMenu;
	 }
};
class WindowsFactory:public Factory
{
	public:
		widget* create_Button(){
			return new WindowsButton;
		}
		widget* create_Menu(){
			return new WindowsMenu;
		}
};
class Client
{
	private:
		Factory* factory;
	public:
		Client(Factory* f){
			factory = f;
		}
		void draw(){
			widget* w = factory->create_Button();
			w->draw();
			display_Window_One();
			display_Window_Two();
		}
		void display_window_One()
		{
			widget* w[] = {
				factory->create_Button();
				factory->create_Menu();
			};
			w[0]->draw();
			w[1]->draw();
		}
		void display_window_Two()
		{
			widget*  w[] = {
				factory->create_Button();
				factory->create_Menu();
			};
			w[0]->draw();
			w[1]->draw();
		}
}
int main()
{
	Factory* factory;
	#ifdef LINUX
		factory = new LinuxFactory;
	#else
		factory = new WindowsFctory;
	#endif
	Client* c = Client(factory);
	c->draw();
}
		
		
	
	
