#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STRINGS 10

//соединяет left с right
//возвращает "цену" пересечения left и right

int get_intersection_cost(char* left,char* right){
        int i;
	if (strlen(left)>0)
		for (i=0;i!=strlen(left);i++){
			unsigned int right_index = 0;
			unsigned int left_index = i;
			while((left[left_index]==right[right_index])&&
				(left_index<strlen(left))&&
				(right_index<strlen(right))){
					left_index++;
					right_index++;
			}
			if (left_index==strlen(left)){
				//есть пересечение длиной (left_index - i)
				//return strlen(left) - (left_index - i);
				return left_index - i;
			}
		}
	return 0;
}

typedef struct {
	int num;
	int lengths[MAX_STRINGS];
} node, *pnode;


void calculate_intersections(char** strings,int count, int current_index,pnode pl){
	int i;
	char* current_string = strings[current_index];
	for (i=0;i!=count;i++)
		if (i!=current_index)
			pl->lengths[i] = get_intersection_cost(current_string,strings[i]);
}

int min_length = 0;
int min_path[MAX_STRINGS];
int total1 = 0;
void get_min_length(
				pnode current_node,
				pnode other_nodes,
				int other_nodes_count,								
				int* visited_nodes_nums,
				int visited_nodes_count,
				int sum_len){
	//необходимо обойти все узлы из all_nodes
	//кроме current_node и тех, что перечислены в prev_nodes_nums



	if (visited_nodes_count == other_nodes_count - 1){
		total1 ++;
		//больше двигаться некуда.
		if (sum_len>min_length){
			visited_nodes_nums[visited_nodes_count] = current_node->num;
			min_length = sum_len;
			memcpy(min_path,visited_nodes_nums,MAX_STRINGS*sizeof(int));
		}
	} else{
		int i;
		//ищем следующий узел		
		for (i=0;i!=other_nodes_count;i++){
			int k,wf=0;
			pnode pn = &(other_nodes[i]);
			int length_to_pn;
			int _sum, _v_count;
			int _visited_nodes[MAX_STRINGS];

			//пропускаем текущий узел
			if (other_nodes[i].num == current_node->num)
				continue;

			//проверяем pn - нет-ли его в пройденном маршруте?
			if (visited_nodes_count)
				for (k=0;k!=visited_nodes_count;k++)
					if (pn->num == visited_nodes_nums[k]){
						wf=1;
						break;
					}
					if (wf)
						continue;

					//следующий узел - pn
					length_to_pn = current_node->lengths[pn->num];
					_sum = sum_len + length_to_pn;

					memset(_visited_nodes,0,MAX_STRINGS*sizeof(int));
					memcpy(_visited_nodes,visited_nodes_nums,visited_nodes_count*sizeof(int));
					_visited_nodes[visited_nodes_count] = current_node->num;
					_v_count = visited_nodes_count + 1;

					get_min_length(pn,other_nodes,other_nodes_count,_visited_nodes,_v_count,_sum);

		}

	}

}


int get_result_length(char** strings, int* path,node* nodes,int count){
	//считаем длину результ. строки
	int i;
	int res_len = 0;
	for (i=0;i!=count;i++){
		int current_string_index = path[i];
		char* c_string = strings[current_string_index];
		res_len += strlen(c_string);

		if (i>0){
			//отнимаем кол-во символов, которое попало в пересечение строк (i+1) и (i)
			//aaaaaaaccc
			//       cccbbbbbb
			int prev_string_index = path[i-1];
			node n = nodes[prev_string_index];
			int intersec_len = n.lengths[current_string_index];
			res_len -= intersec_len;

// 			
// 			char* prev_string = strings[prev_string_index];
// 			int intersec_len = strlen(prev_string) - cost;
			

		}
	}




	return res_len;
}

int main(int argc,char** argv){




	//Пример работы программы1
	/*
	int N = 3;
	char* strings[] = {
		"caacccca",
		"accaacccc",
		"cabaccaac"
	};
	*/


	//Пример ответа2	
	/*
	int N = 5;
	char* strings[] = {
		"bba",
		"babccaab",
		"abccaabac",
		"aabacacab",
		"acabaab"
	};
	*/


	//Пример ответа 3
	/*
	int N = 10;
	char* strings[] = {
		"acbabcaac",
		"cbca",
		"bbaa",
		"bcacaab",
		"acbcccab",
		"bcbcbab",
		"bbbccbabca",
		"accccabba",
		"cbaca",
		"accaabaaab"

	};
	*/
	
	
	
	



	int i;

	node ints[MAX_STRINGS];
	pnode plens;
	char *strings[MAX_STRINGS];
	int N;

	/*
	char *strings[] = {
		"aabccbb",
		"babc",
		"bcabaacab",
		"bbccbaabc",
		"bcbcbbbcbb"

	};
	N = 5;
	*/


	memset(strings,0,MAX_STRINGS*sizeof(char*));

	scanf("%d",&N);
	i = 0;
	while(i!=N){
		strings[i] = (char*)malloc(1024); //макс. длина строки в условиях не указана
		scanf("%s",strings[i]);
		i++;
	}
	
	
	
	memset(ints,0,MAX_STRINGS*sizeof(node));

	//считаем пересечения строк (каждая с каждой)
	plens = ints;
	for (i=0;i!=N;i++){
		calculate_intersections(strings,N,i,plens);
		plens->num = i;
		plens++;
	}
		


	min_length = 0;
	memset(min_path,0,MAX_STRINGS*sizeof(int));

	for (i=0;i!=N;i++){
		int visited_nodes[MAX_STRINGS];
		memset(visited_nodes,-1,MAX_STRINGS*sizeof(int));
		get_min_length(&(ints[i]),ints,N,visited_nodes,0,0);
	}
		

	//printf("-------- total1=%d ------\n",total1);

	//вывод на экран последовательности соединения строк
//  	for (i=0;i!=N;i++)
//  		printf("%s\n",strings[min_path[i]]);


	min_length = get_result_length(strings,min_path,ints,N);
	printf("%d\n",min_length);


	
	for (i=0;i!=N;i++)
		if (strings[i]!=0)
			free(strings[i]);
			
	return 0;


}