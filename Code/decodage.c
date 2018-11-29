#include "decodage.h"

void decodage(char * fentree, char * fsortie){
	FILE* entree = NULL;
	FILE* sortie = NULL;
	char ligne[20];
	char caract;
	char opcode[5];
	char op1[5];
	int op1T;
	char op2[5];
	int op2T;
	char op3[5];
	int op3T;
	char ligneTrad[20];
	int indice = 0;
	int i =0;
	int j = 0;

//-------------OUVERTURE FICHIERS----------------
	while ( entree == NULL && sortie == NULL){
		entree = fopen(fentree,"r+");
		sortie = fopen(fsortie,"w+");
	}
	printf("fichier ouvert\n");

//------------LECTURE ET TRI LIGNE PAR LIGNE--------
	while((caract=fscanf(entree,"%c",&caract))!=EOF){
		fseek(entree,-1,SEEK_CUR);
		fgets(ligne,20,entree);
		printf("ligne %s\n", ligne);				//gerer le cas avec un seul mot à la fin
		while (ligne[i] != '\0' && ligne[i]!=' '){
			opcode[j] = ligne[i];
			i++;
			j++;
		}
		opcode[j]='\0';
		j = 0;
		i++;
		printf("opcode %s\n",opcode );
		while (i<strlen(ligne) && ligne[i]!=','){
	/*		if (ligne[i]=='$'){
				i++;
			}
			else{*/
				op1[j] = ligne[i];
				i++;
				j++;
	//		}
		}
		op1[j]='\0';
		j=0;
		i++;
		printf("op1 %s\n", op1);
	 	while (ligne[i]!= ',' && i<strlen(ligne)){
	/*		if (ligne[i]=='$'){
				i++;
			}
			else{*/
				op2[j] = ligne[i];
				i++;j++;
	//		}
		}
		op2[j]='\0';
		j=0;
		i++;
		printf("op2 %s\n", op2);
		while (i<strlen(ligne)){
			op3[j] = ligne[i];
			i++;j++;
		}
		op3[j]='\0';
		j=0;
		i=0;
		printf("op3 %s\n", op3);

		//--------------CONVERSION EN HEXA------------------
		if(strchr(op1,'$') != NULL){
			op1T=atoi(strchr(op1,'$')+1);	//conversion char to int
		}
		else{
			op1T=atoi(op1);
		}
		if(strchr(op2,'$') != NULL){
			op2T=atoi(strchr(op2,'$')+1);	//conversion char to int
		}
		else
		{
			op2T=atoi(op2);
		}
		if(strchr(op3,'$') != NULL){
			op3T=atoi(strchr(op3,'$')+1);	//conversion char to int
		}
		else{
			op3T=atoi(op3);
		}


		if (strcmp(op1,"") && !strcmp(op2,"") && !strcmp(op3,"")){	//vérifie type J
//-----------CAS J-------------------------------
			while (i<2 && strcmp(opcode,codeJ[i])){
				i++;
				indice = i;
			}
				printf("%s\n", codeJ[indice]);
				sprintf(ligneTrad,"%d %x\0",codeEqJ[indice],op1T);
				printf("ligne trad %s\n",ligneTrad );
				fprintf(sortie, "%s\n", ligneTrad);			// Ajout Adrian
				i=0;
		}
		else if(strchr(op3,'$')==NULL){
			while (i<8 && strcmp(opcode,codeI[i])){
				i++;
				indice = i;
			}
				sprintf(ligneTrad,"%x %x %x %x\0",codeEqI[indice],op1T,op2T,op3T);
				printf("ligne trad %s\n",ligneTrad );
				fprintf(sortie, "%s\n", ligneTrad);			// Ajout Adrian
				i=0;
		}
		else{
			while (i<8 && strcmp(opcode,codeR[i])){
				i++;
				indice = i;
			}
				sprintf(ligneTrad,"%x %x %x %x\0",codeEqR[indice],op1T,op2T,op3T);
				printf("ligne trad %s\n",ligneTrad );
				fprintf(sortie, "%s\n", ligneTrad);			// Ajout Adrian
				i=0;

		}
	}
}


int main(int argc, char* argv[]){

	decodage(argv[1],argv[2]);

}
