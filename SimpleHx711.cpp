#include <iostream>
#include <hx711/common.h>

int main() {
	using namespace HX711;

	// create a SimpleHX711 object using GPIO pin 2 as the data pin,
	// GPIO pin 3 as the clock pin, -370 as the reference unit, and
	// -367471 as the offset
	SimpleHX711 hx(2, 3, 100, 115000);

	// set the scale to output weights in ounces
	hx.setUnit(Mass::Unit::G);

	// constantly output weights using the median of 35 samples
	while(1){
		std::cout << hx.weight(35) << std::endl;
		
		if((float)hx.weight(35) > 500.0){
			std::cout << "Enter if" << std::endl;
			// JSON 문서에 저장할 데이터
			// JSON 문서에 저장할 데이터
			char *title = "Inception";
			int year = 2010;
			int runtime = 148;
			char *genre = "Sci-Fi";
			char *director = "Christopher Nolan";
			char actors[5][30] = {
				"Leonardo DiCaprio",
				"Joseph Gordon-Levitt",
				"Ellen Page",
				"Tom Hardy",
				"Ken Watanabe"
			};
			double imdbRating = 8.8;

			FILE *fp = fopen("example.json", "w");    // 쓰기 모드로 파일 열기

			// JSON 문법에 맞춰서 fprintf 함수로 값 출력
			fprintf(fp, "{\n");
			fprintf(fp, "  \"Title\": \"%s\",\n", title);
			fprintf(fp, "  \"Year\": %d,\n", year);
			fprintf(fp, "  \"Runtime\": %d,\n", runtime);
			fprintf(fp, "  \"Genre\": \"%s\",\n", genre);
			fprintf(fp, "  \"Director\": \"%s\",\n", director);
			fprintf(fp, "  \"Actors\": [\n");
			fprintf(fp, "    \"%s\", \n", actors[0]);
			fprintf(fp, "    \"%s\", \n", actors[1]);
			fprintf(fp, "    \"%s\", \n", actors[2]);
			fprintf(fp, "    \"%s\", \n", actors[3]);
			fprintf(fp, "    \"%s\" \n", actors[4]);
			fprintf(fp, "  ],\n");
			fprintf(fp, "  \"imdbRating\": %.1f\n", imdbRating);
			fprintf(fp, "}\n");

			fclose(fp);    // 파일 닫기
		}
	}
	
  return 0;

}
