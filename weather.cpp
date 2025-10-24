#include<iostream>
#include<random>
#include<ctime>
#include<string>

int pnpF(int a, int b){
  std::mt19937 generator(time(0));
  std::uniform_int_distribution<int> distribution(1, a+b);
  int randNum = distribution(generator);
  if (randNum <= a ){
    return 1;
  }else{
    return 0;
  }
}

void fOutput(int a, std::string c){
  //char situations[5]  = {"sunny and humid", "sunny and not humid", "raining and windy", "raining and not windy","overcast"};

  std::cout<<"Weather: "<< c << std::endl;
  if (a == 0){
  
    std::cout<<"Decision: not play"<<std::endl;
  }else{
    std::cout<<"Decision: play"<<std::endl;
  }
}
  

int main(){
  //std::cout << pnpF(9,5) << std::endl;
  int weather = 0;
  int randR = pnpF(9, 5);
  std::string situations[5]  = {"sunny and humid", "sunny and not humid", "raining and windy", "raining and not windy","overcast"};

  do{
    std::cin >> weather ;
    if (weather == -1){
      return 0;
    }
  }while(weather != 1 && weather != 2 && weather != 3 && weather != 4 && weather != 5);





  
  std::string status = situations[weather - 1];
  if (randR == 0){
    std::cout<<"Weather: "<< status << std::endl;
    std::cout<<"Decision: not play"<<std::endl;
    return 0;
  }
  

  switch(weather){
    case 1:
      if (pnpF(2,3) == 0){
	std::cout<<"Weather: "<< status << std::endl;
	std::cout<<"Decision: not play"<<std::endl;
	return 0;
      }else{
	fOutput(pnpF(9,4),status);
	return 0;
      }
      
    case 2:
      if (pnpF(2,3) == 0){
	std::cout<<"Weather: "<< status << std::endl;
	std::cout<<"Decision: not play"<<std::endl;
	return 0;
      }else{
	fOutput(pnpF(2,5), status);
	return 0;
      }

    case 3:
      if (pnpF(3,2) == 0){
	std::cout<<"Weather: "<< status << std::endl;
	std::cout<<"Decision: not play"<<std::endl;
	return 0;
      }else{
	fOutput(pnpF(2,5),status);
	return 0;
      }

    case 4:
      if (pnpF(3,2) == 0){
	std::cout<<"Weather: "<< status << std::endl;
	std::cout<<"Decision: not play"<<std::endl;
	return 0;
      }else{
	fOutput(pnpF(9,3),status);
	return 0;
      }

    case 5:
      std::cout<<"Weather: overcast"<<std::endl;
      std::cout<<"Decision: play"<<std::endl;
    //case default:
  }
}

