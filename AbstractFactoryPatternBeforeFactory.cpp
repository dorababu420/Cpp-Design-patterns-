/*AbstractFactory DesinPattern Before and After*/
#include <iostream>
using namespace std;
//Abstract Base Factory
class widget{
    public:
	    virtual void draw() = 0;
};
//concrete factory family 1
#ifdef LINUX
    class LinuxButton:public Widget
	{
	    public:
		    void draw(){
			    cout << "LinuxButton\n" << endl;
            }
    };
    class LinuxMenu:public Widget
    {
        public:
            void draw(){
                cout << "LinuxMenu\n" << endl;
            }
    };
#else
    class WindowsButton:public widget
	{
	    public:
		void draw()
		{
		    cout << "WindowsButton\n" << endl;
		}
	};
	class WindowsMenu:public widget
	{
	    public:
		    void draw()
			{
			    cout << "WindowsMenu\n" << endl;
		    }
	};
#endif
class Client
{
    public:
	void draw(){
		#ifdef LINUX
			Widget* w = new LinuxButton;
		#elif
			widget* w = new WindowsButton;
		#endif
		w->draw();
		void display_Window_One();
		void display_Windows_Two();
	}
	void display_Window_One(){
		#ifdef LINUX
			widget* w[] = {
				new LinuxButton;
				new LinuxMenu;
		};
		#else
			windget* w[] = {
				new WindowsButton;
				new WindowsMenu;
			};
		#endif
		w[0]->draw();
		w[1]->draw();
	}
	void display_Window_Two(){
		#ifdef LINUX
			widget* w[] = {
				new LinuxButton;
				new LinuxMenu;
		};
		#else
			windget* w[] = {
				new WindowsButton;
				new WindowsMenu;
			};
		#endif
		w[0]->draw();
		w[1]->draw();
	}
};
int main()
{
   Client* c = new Client;
   c->draw();
}
	
	
	  
	
		
