#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void vectorTest(){
	
}
void mapTest(){
	map<string, int> m;
	cout << m["feg"] << "\n";
	m["feg"] = 3;
	cout << m["feg"] << "\n";
	
//	cout << m.at("fff") << "\n"; //오류발생  
	cout << m.at("feg") << "\n";
	
	if(  m.find("fff") == m.end())	cout << "not found" << "\n";
	auto a = m.find("feg");
	cout << &a << "\n";
//	cout << *a << "\n"; // 오류발생

	m.insert({"def",5});
	cout << m["def"] << "\n";
	cout << m.at("def") << "\n";
	cout << m.size() << "\n";
	
	// 두번째 insert는 무시된다..  
	m.insert({"def",10});
	cout << m["def"] << "\n";
	cout << m.at("def") << "\n";
	cout << m.size() << "\n";
 
	m["def"] = 15;
	cout << m["def"] << "\n";
	cout << m.at("def") << "\n";
	cout << m.size() << "\n";
 
	// 순회
	for(pair<string,int> entry : m){
		cout << entry.first << "," << entry.second << "\n";
	}
	
	// 순서 뒤집기 
	vector<pair<string,int>> v(m.begin(),m.end());
	sort(v.begin(),v.end(),[](pair<string,int> a, pair<string,int> b) {
		if(a.second == b.second) return a.first < b.first;
		return  a.second < b.second;
	});
	for(pair<string,int> entry : v){
		cout << entry.first << "," << entry.second << "\n";
	} 
}

bool pair_cmp(pair<string,int> a, pair<string,int> b) {
	if(a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
struct Music{
	int number, play;
	
	Music(int p_number, int p_play) : number(p_number), play(p_play){}
	bool operator < (const Music & a ) const{
        if(play == a.play) return number < a.number;
		return play > a.play;
	}
};
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> countMap;
    map<string, vector<Music>> musicMap;
    int size = genres.size();
    for(int i=0; i<size; i++){
    	string genre = genres[i];
    	int play = plays[i];
    	if(countMap.find(genre) == countMap.end()){
    		countMap.insert({genre,play});
		}else{
			countMap[genre] += play; 
		}
		
    	Music m = {i, play};
		if(musicMap.find(genre) == musicMap.end()){
    		vector<Music> temp;
    		temp.push_back(m);
			musicMap.insert({genre,temp});
		}else{
			musicMap[genre].push_back(m);
			sort(musicMap[genre].begin(),musicMap[genre].end());
		}
	}
	
	vector<pair<string,int>> v(countMap.begin(),countMap.end());
	sort(v.begin(),v.end(),pair_cmp);
	for(pair<string,int> entry : v){
		cout << entry.first << "," << entry.second << "\n";
		vector<Music> musics = musicMap[entry.first];
		if(musics.size() > 1){
            answer.push_back(musics[0].number);
            answer.push_back(musics[1].number);
        }else{
            answer.push_back(musics[0].number);
        }
	}
	
	// 순회
	for(pair<string,vector<Music>> entry : musicMap){
		cout << "===" << entry.first << "===\n" ;
		for(Music m : entry.second){
			cout << m.number << ":"  << m.play << "\n";
		}
	}
	
    return answer;
}

int main(){
	// #구현 
	mapTest();
	vector<string> genres = {"classic","pop", "classic","classic","pop"};
	vector<int> plays = {500,600,150,800,2500};
	vector<int> a = solution(genres,plays);
	for(int b: a) cout << b << ",";
	return 0;
}
