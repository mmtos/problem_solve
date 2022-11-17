#include<bits/stdc++.h>
using namespace std;

void printMap(map<string, int> &m){
	// pair가 맞다. 
	for(pair<string,int> i : m){
		cout << i.first << ":" <<  i.second << ", ";
	}
	cout << "\n";
}

void printMap(unordered_map<string, int> &m){
	// pair가 맞다. 
	for(pair<string,int> i : m){
		cout << i.first << ":" <<  i.second << ", ";
	}
	cout << "\n";
}

map<string, int> createTestDummyMap(){
	map<string, int> m;
	m.emplace("test2",2);
	m["test3"] = 3;
	m.insert({"test1",1});
	return m;
}

unordered_map<string, int> createTestDummyUnOrderedMap(){
	unordered_map<string, int> m;
	m.emplace("test2",2);
	m["test3"] = 3;
	m.insert({"test1",1});
	return m;
}

void basicOperation(){
	map<string, int> m = createTestDummyMap();
	
	m["test3"] = 5;
	
	printMap(m);
	
	auto foundedIter = m.find("test4");
	if(foundedIter != m.end()){
		cout << foundedIter -> first << ":" << foundedIter -> second << "\n";
	}else{
		cout << "not found.." << '\n';
	}
	
	if(m["test4"] == 0){
		cout << "implicit insert";
	}
	printMap(m);
	
	// 맵에 요소가 있는지 없는지를 확인하고 맵에 데이터를 할당하기 
	if(m.find("test5") == m.end()){
		m.emplace("test5", 5);
	}
	
	m["test1"]++;
	printMap(m);
	
} 

// https://eehoeskrap.tistory.com/263 
void iteratorTest(){
	map<string, int> emptyMap;
	// 아무 원소도 없는 컨테이너의 begin()과 end()는 같다. 
	cout << (emptyMap.begin() == emptyMap.end()) << "\n";
	
	map<string, int> m = createTestDummyMap();
	// 순회 
 	for(map<string,int>::iterator it = m.begin() ; it != m.end() ; it++){
 		cout << it -> first << ":" << it -> second << " ";
	} 
	
	// m.end()는  past-the-end iterator 
	auto last = --m.end();  
	cout << (*last).first << ":" << (*last).second;
}

// 해시테이블을 사용하여 평균적으로 탐색 삽입 삭제가 O(1)로 빠르나,
// 최악의경우 O(N)까지 갈수있어 그냥 map을 쓰는게 유리함  
void unOrderedMapTest(){
	unordered_map<string, int> umap = createTestDummyUnOrderedMap();
	map<string, int> map = createTestDummyMap();
	
	printMap(umap); // 내부 pair가 정렬되어 있지 않다.  
	printMap(map);
	
}

int main(){
	// https://cplusplus.com/reference/map/map/
	//std의 map은 red black tree? 정렬, 균형,  
	// 탐색, 삽입, 삭제에 O(logN)이 걸림 왜? 
	cout << "\n===basicOperation===\n";
	basicOperation();
	cout << "\n===iteratorTest===\n";
	iteratorTest();
	cout << "\n===unOrderedMapTest===\n";
	unOrderedMapTest();
	
	return 0;
}

 
