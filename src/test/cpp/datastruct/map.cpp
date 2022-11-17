#include<bits/stdc++.h>
using namespace std;

void printMap(map<string, int> &m){
	// pair�� �´�. 
	for(pair<string,int> i : m){
		cout << i.first << ":" <<  i.second << ", ";
	}
	cout << "\n";
}

void printMap(unordered_map<string, int> &m){
	// pair�� �´�. 
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
	
	// �ʿ� ��Ұ� �ִ��� �������� Ȯ���ϰ� �ʿ� �����͸� �Ҵ��ϱ� 
	if(m.find("test5") == m.end()){
		m.emplace("test5", 5);
	}
	
	m["test1"]++;
	printMap(m);
	
} 

// https://eehoeskrap.tistory.com/263 
void iteratorTest(){
	map<string, int> emptyMap;
	// �ƹ� ���ҵ� ���� �����̳��� begin()�� end()�� ����. 
	cout << (emptyMap.begin() == emptyMap.end()) << "\n";
	
	map<string, int> m = createTestDummyMap();
	// ��ȸ 
 	for(map<string,int>::iterator it = m.begin() ; it != m.end() ; it++){
 		cout << it -> first << ":" << it -> second << " ";
	} 
	
	// m.end()��  past-the-end iterator 
	auto last = --m.end();  
	cout << (*last).first << ":" << (*last).second;
}

// �ؽ����̺��� ����Ͽ� ��������� Ž�� ���� ������ O(1)�� ������,
// �־��ǰ�� O(N)���� �����־� �׳� map�� ���°� ������  
void unOrderedMapTest(){
	unordered_map<string, int> umap = createTestDummyUnOrderedMap();
	map<string, int> map = createTestDummyMap();
	
	printMap(umap); // ���� pair�� ���ĵǾ� ���� �ʴ�.  
	printMap(map);
	
}

int main(){
	// https://cplusplus.com/reference/map/map/
	//std�� map�� red black tree? ����, ����,  
	// Ž��, ����, ������ O(logN)�� �ɸ� ��? 
	cout << "\n===basicOperation===\n";
	basicOperation();
	cout << "\n===iteratorTest===\n";
	iteratorTest();
	cout << "\n===unOrderedMapTest===\n";
	unOrderedMapTest();
	
	return 0;
}

 
