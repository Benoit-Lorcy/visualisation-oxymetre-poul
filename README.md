# Visualisation Oxymetre Poul
Project réalisé en cir 3 (3ème année d'étude à l'ISEN) à l'occasion d'un project de groupe. \
Cette partie du project était à réalisé en C et permet :
* Récupération des valeurs mesurées de la lumière rouge (ACR et DCR) et de l'infra-rouge (ACIR et DCIR) via liaison USB
* Traitement des informations reçues afin d'éliminer les signaux parasites
* Calcul de l'oxymétrie et de fréquence cardiaque
* Visualisation des résultats via une interface utilisateur

## Build and Run the program
Build the program :
```
> make
```

Run the program with a file :
```
> ./prog.exe -file path_to_file 
```
Run the program with usb (only work when compiled on windows) :
```
> ./prog.exe -usb
```