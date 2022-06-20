#include <iostream>
#include <ostream>
#include <string.h>

#define HEX_VALUE_CHECK (v == '1'|| v == '2' || v == '3' || \
						v == '4'|| v == '5' || v == '6' || \
						v == '7'|| v == '8' || v == '9' || \
						v == 'a'|| v == 'b' || v == 'c' || \
						v == 'd'|| v == 'f' || v == '0')

using namespace std;

class Hexadecimal{
	private:
		string value;
		void check_valid_value(){
			for(char v : value){
				if(strlen(value.c_str()) > 6){
					value = "000000";
					return;
				};
				if(!HEX_VALUE_CHECK){
					value = "000000";
					return;
				}
			}
		}

	public:
		Hexadecimal(){
			value = "ffffff";
		}
		Hexadecimal(string value){
			this->value = value;
			check_valid_value();
		}
		string get_value(){
			return value;
		}

		friend ostream& operator << ( ostream& out, 
									const Hexadecimal 
									&color);

};

class RGB{
	private:
		int red,
			green,
			blue
			;
		void check_bounds(){
			red = max( min(255, red), 0);
			green = max( min(255, green), 0);
			blue = max( min(255, blue), 0);
		}

	public:
		RGB(){
			red = 111;
			green = 111;
			blue = 111;
		}
		RGB(int red, int green, 
			int blue){
			this->red = red;
			this->green = green;
			this->blue = blue;
			check_bounds();
		}

		int get_red(){
			return red;
		}

		int get_green(){
			return green;
		}

		int get_blue(){
			return blue;
		}

		friend ostream& operator << ( ostream& out, 
									const RGB &color);

};

class Converter{
    public:
    	static RGB &convert_color(Hexadecimal &color){  
    					string value = color.get_value();

    					int red = Converter::get_dec_digit( value[0] ) << 4;
    					red = red | Converter::get_dec_digit( value[1] );
    					
    					int green = Converter::get_dec_digit( value[2] ) << 4;
    					green = green | Converter::get_dec_digit( value[3] );
    					
    					int blue = Converter::get_dec_digit( value[4] ) << 4;
    					blue = blue | Converter::get_dec_digit( value[5] );
    					

    					return *new RGB(red, green, blue);
    				};

        static Hexadecimal &convert_color(RGB &color){  

        				string value = "";

        				value += get_hex_digit( color.get_red() >> 4 );
        				value += get_hex_digit ( (color.get_red() & 15));
        				
        				value += get_hex_digit( color.get_green() >> 4 );
        				value += get_hex_digit ( (color.get_green() & 15));
        				
        				value += get_hex_digit( color.get_blue() >> 4 );
        				value += get_hex_digit ( color.get_blue() & 15);
        				

    					return *new Hexadecimal(value);
    				};

    private: Converter(){};
    		 static int get_dec_digit(char v){
    		 	switch(v){
    		 		default: 	  return 0;
    		 		case '1': 	  return 1;
    		 		case '2': 	  return 2;
    		 		case '3': 	  return 3;
    		 		case '4': 	  return 4;
    		 		case '5': 	  return 5;
    		 		case '6': 	  return 6;
    		 		case '7': 	  return 7;
    		 		case '8': 	  return 8;
    		 		case '9': 	  return 9;
    		 		case 'a': 	  return 10;
    		 		case 'b': 	  return 11;
    		 		case 'c': 	  return 12;
    		 		case 'd': 	  return 13;
    		 		case 'e': 	  return 14;
    		 		case 'f': 	  return 15;
    		 	}
    		 };
    		 static char get_hex_digit(int v){
    		 	switch(v){
    		 		default: 	  return '0';
    		 		case  1: 	  return '1';
    		 		case  2: 	  return '2';
    		 		case  3: 	  return '3';
    		 		case  4: 	  return '4';
    		 		case  5: 	  return '5';
    		 		case  6: 	  return '6';
    		 		case  7: 	  return '7';
    		 		case  8: 	  return '8';
    		 		case  9: 	  return '9';
    		 		case 10: 	  return 'a';
    		 		case 11: 	  return 'b';
    		 		case 12: 	  return 'c';
    		 		case 13: 	  return 'd';
    		 		case 14: 	  return 'e';
    		 		case 15: 	  return 'f';
    		 	}
    		 };

};

ostream& operator << ( ostream& out, const RGB &color ){
	
	out << "| RGB COLOR --->>>> "
		<< "(" << color.red  << ", "
		<< color.green << ", "
		<< color.blue << ")"
		<< endl; 


	return out;
}

ostream& operator << ( ostream& out, const Hexadecimal &color ){
	
	out << "| HEXADECIMAL COLOR --->>>> #"
		<< color.value << endl;

	return out;
}

int main(){
	
	auto my_color = new RGB();
	auto other_color = new RGB(255, 255, 255);
	auto hex_color = new Hexadecimal();
	auto other_hex_color = new Hexadecimal("157adf");

	cout << *my_color;
	cout << *other_color;
	cout << *hex_color;
	cout << *other_hex_color;
	
	cout << *new RGB(-14848, 255555, 99999999);
	cout << *new Hexadecimal("-144848484dfd");
	cout << *new Hexadecimal("ffffffffffff");
	
	RGB &color1_convert = *new RGB(157, 244, 10);
	Hexadecimal &color2_convert = *new Hexadecimal("aadf14");
	
	cout << color1_convert;
	cout << Converter::convert_color(color1_convert);
	cout << color2_convert;
	cout << Converter::convert_color(color2_convert);

	return 0;
}