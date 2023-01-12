#include <bits/stdc++.h>
#include <set>
#include <vector>
#include <queue>

using namespace std;

void setFindTest(){
    set<int> tt;
    tt.insert(3);
	auto t = tt.find(3);
	if(t == tt.end()){
		cout << "not found" << "\n";
	}else{
		cout << "found" << "\n";
		cout << *t << "\n";
	}
}

int solution2(int n, vector<vector<int>> wires){
	// 2. 각 노드에서 시작하는 서브트리의 총 노드 개수를 메모한다 -> 송전탑 기준으로 나누었을때 각 서브트리 송전탑 개수 찾기
    // 실패함. 
		// 1. 암묵적으로 트리 내 노드간 양방향 이동이 가능했음.
		// 따라서 특정 노드를 root로 두고 나누려다 보니 서브 트리를 특정할 수 없음 
		// 2. 애초에 노드로 나누기보다 간선으로 나눴어야 했음. 
	sort(wires.begin(), wires.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
	
    vector<set<int>> memo(n+1, set<int>());
	for(int i=0;i<wires.size();i++){
    	vector<int> wire = wires[i];
    	int from = wire[0];
    	int to = wire[1];
    	memo[from].insert(from);
    	memo[from].insert(to);
    	for(int j = 1; j< memo.size();j++){
    		
    		set<int> nodes = memo[j];
    		if(nodes.find(from) != nodes.end()) nodes.insert(to);
			cout << "wire :" << i << "th : " << from << "," << to << "\n";
    		cout << j << "node set : [";
    		for(int t : nodes){
    			cout << t << ",";
			}
			cout << "]\n";
			memo[j] = nodes;
		}
	}
	vector<int> nodeCount(n+1,0);
	for(int i=1;i<memo.size();i++){
		//cout << i << "node : " << memo[i].size() << "\n";
		nodeCount[i] = memo[i].size();
	}
	int answer = INT_MAX;
	for(int i=1;i<nodeCount.size();i++){
		answer = min(answer, abs(n- 2 * nodeCount[i]));
	} 
	cout << "answer : " << answer;
	return answer;
}

const int maxN = 101;
int visited[maxN];

int nodeDiff(int n, vector<vector<int>> wires, pair<int,int> cut) {
    queue<int> q;
    int sp1, sp2, cnt1 = 1, cnt2 = 1;
    tie(sp1,sp2) = cut;
    
	cout << sp1 << "," << sp2 << "\n";
	vector<vector<int>> graph(maxN, vector<int>());
    // 양방향
    for(int i=0; i<wires.size();i++){
    	graph[wires[i][0]].push_back(wires[i][1]);
    	graph[wires[i][1]].push_back(wires[i][0]);
	}
    
    q.push(sp1);
    visited[sp1] = 1;
    while(q.size()){
    	int currNode = q.front(); q.pop();
    	vector<int> nextNodes = graph[currNode];
    	for(int nextNode : nextNodes){
    		if(visited[nextNode]) continue;
    		visited[nextNode] = 1;
    		cnt1++;
    		q.push(nextNode);
		}
	}
	
	fill(&visited[0],&visited[0] + maxN,0);
	
	q.push(sp2);
    visited[sp2] = 1;
    while(q.size()){
    	int currNode = q.front(); q.pop();
    	vector<int> nextNodes = graph[currNode];
    	for(int nextNode : nextNodes){
    		if(visited[nextNode]) continue;
    		visited[nextNode] = 1;
    		cnt2++;
    		q.push(nextNode);
		}
	}
	fill(&visited[0],&visited[0] + maxN,0);
	cout << cnt1 << "," << cnt2 << "\n";
	return abs(cnt1-cnt2);
	
}

int sizeOfIsland(vector<vector<int>> wires) {
	//한쪽의 송전탑 개수만 구해도 나머지쪽을 알수있다.
	//k번 송전탑은 두개의 섬 중에 한 곳엔 반드시 포함되기때문에 1번 송전탑 기준으로 찾으면 된다.  
    queue<int> q;
    int cnt = 0;
    
	vector<vector<int>> graph(maxN, vector<int>());
    for(int i=0; i<wires.size();i++){
    	graph[wires[i][0]].push_back(wires[i][1]);
    	graph[wires[i][1]].push_back(wires[i][0]);
	}
    
    q.push(1);
    visited[1] = 1;
    cnt++;
    while(q.size()){
    	int currNode = q.front(); q.pop();
    	vector<int> nextNodes = graph[currNode];
    	for(int nextNode : nextNodes){
    		if(visited[nextNode]) continue;
    		visited[nextNode] = 1;
    		cnt++;
    		q.push(nextNode);
		}
	}
	
	fill(&visited[0],&visited[0] + maxN,0);
	
	return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    // 1. 먼저 트리를 나누고 서브트리 순회 후 송전탑 개수 비교 -> 최소값 찾기
    int answer = INT_MAX;
    for(int i=0 ; i< wires.size();i++){
    	vector<vector<int>> temp(wires);
    	temp.erase(temp.begin() + i);
    	for(vector<int> wire:temp){
    		cout << wire[0] << ":" << wire[1] << ",";
		}
		cout << "\n";
		//answer = min(answer,nodeDiff(n,temp, {wires[i][0],wires[i][1]}));
		int cnt = sizeOfIsland(temp);
		answer = min(answer,abs(n - cnt - cnt));
	}
    cout << answer << "\n";
    return answer;
}

int main(){
    // #완전탐색
	int n = 9;
	vector<vector<int>> wires = {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};
	solution(n, wires);
	return 0;
}

