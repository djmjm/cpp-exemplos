#include <iostream>
#include <map>
#include <set>
#include <time.h>

#define RANDOMIZE srand(time(NULL))

#define CONTAINS_URL urls_origin.find(param)\
				     != urls_origin.end()

#define URL_REDIRECT urls_redirected.find(param)\
				     != urls_redirected.end()

#define URL_GENERIC "https://www.shortlink.com/"

#define PRINT 		cout << 
#define BREAK_LINE 	<< endl

using namespace std;

class UrlShort{
	private:
			set<string> urls_origin;
			set<string> urls_generated;
			map<string, string> urls_redirected;

			string generate_new_url(){
				char key[6];

				do{
					key[0] = (char)( 'a' + rand() % 24 );
					key[1] = (char)( 'a' + rand() % 24 );
					key[2] = (char)( 'a' + rand() % 24 );
					key[3] = (char)( 'a' + rand() % 24 );
					key[4] = (char)( 'a' + rand() % 24 );
					key[5] = (char)( 'a' + rand() % 24 );

					string 
					string_final = "";
					string_final += string(1,key[0]) + key[1] + key[2] +
							       key[3] + key[4] + key[5] ;

					bool is_new_url = urls_generated.find(
										string_final
									  )
									  == urls_generated.end();

					if(is_new_url){ return 	string(URL_GENERIC +
											string_final); };

				}while(true);
			}

	public: 
			UrlShort(){
				RANDOMIZE;
			}

			void add_url(string url){
				string param = url;
				if(CONTAINS_URL){ return; };

				urls_origin.insert(param);

				string new_url = generate_new_url();
				urls_generated.insert(new_url);

				urls_redirected.insert(make_pair(url, new_url));
			}

			string get_short_link(string url_origin){
				string param = url_origin;

				if(URL_REDIRECT){
					return 
							urls_redirected[url_origin]
							+ "  ---->>>>>  " +
							url_origin
							;
				}else{
					return "URL -> " + url_origin + " :: NOT FOUND!";
				}
			}
};

int main(){

	UrlShort &urls = *new UrlShort();

	PRINT
		urls.get_short_link("https://www.gremio.net")
	BREAK_LINE;

	urls.add_url("https://www.gremio.net");

	PRINT
		urls.get_short_link("https://www.gremio.net")
	BREAK_LINE;

	urls.add_url("https://www.gremio.net");

	PRINT
		urls.get_short_link("https://www.gremio.net")
	BREAK_LINE;

	urls.add_url("https://www.gremio.net");
	urls.add_url("https://www.google.com");
	urls.add_url("https://www.facebook.com");
	urls.add_url("https://www.gmail.com");

	PRINT
		urls.get_short_link("https://www.gremio.net")
	BREAK_LINE;

	PRINT
		urls.get_short_link("https://www.gmail.com")
	BREAK_LINE;

	PRINT
		urls.get_short_link("https://www.google.com")
	BREAK_LINE;

	PRINT
		urls.get_short_link("https://www.gremio.net")
	BREAK_LINE;

	PRINT
		urls.get_short_link("https://www.internacional.com.br")
	BREAK_LINE;

	return 0;
}