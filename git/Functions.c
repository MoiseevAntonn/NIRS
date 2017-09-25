#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inplace(int *a, int l1, int l2){		//������� ��� ���������������� �������
	int tmp, i, j, l;
	int *b;
	if (l1 > l2) {
		b = (int*)malloc(l1*l1*sizeof(int));	//�������� ��������������� ���������� �������(��� �������� ���������������)
		l = l1;									//������� ������� � ������������ ����������� ���������
		for (i = 0; i < l2; i++){
			for (j = 0; j < l1; j++){
				*(b + i*l + j) = *(a + i*l + j);//����������� ��������������� ������� �������� �� �������� 
			}
		}

	}
	else {
		b = (int*)malloc(l2*l2*sizeof(int));	//���� �����,�� ��� ������,���� ���������� �����>���������� ��������
		l = l2;
		for (i = 0; i < l2; i++){
			for (j = 0; j < l1; j++){
				*(b + i*l + j) = *(a + i*l1 + j);
			}
		}


	}
	for (i = 0; i < l; i++){					//�������� ��������������� ���������� �������
		for (j = 0; j < i; j++){
			tmp = *(b + i*l + j);
			*(b + i*l + j) = *(b + j*l + i);
			*(b + j*l + i) = tmp;
		}
	}



	if (l1 > l2){								//������������ �������� ������� ����� ���������
		for (i = 0; i < l1; i++){				//��� ������,����� ���������� �������� > ������ ���������� �����
			for (j = 0; j < l2; j++){
				*(a + i*l2 + j) = *(b + i*l1 + j);

			}
		}
	}
	else {										//���� �����,�� 
		for (i = 0; i < l1; i++){				//��� ������,����� ���������� �������� <��� = ������ ���������� �����
			for (j = 0; j < l2; j++){
				*(a + i*l2 + j) = *(b + i*l2 + j);

			}
		}
	}
	free(b);									//�������� ��������������� �������
	return a;

}

int printArr(int *a, int l1, int l2){	//������� ������ ���������� �������.
	int i, j;							//L1 - ���������� ��������
	printf("\n");						//L2 - ���������� �����
	for (i = 0; i < l2; i++){
		for (j = 0; j < l1; j++){
			printf("%d", *(a + i*l1 + j));
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}