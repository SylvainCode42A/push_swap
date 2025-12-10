# push_swap

2 — Mode medium → O(n√n)

Ce qu’il faut faire

Un algo “chunk” :
	•	tu découpes ta stack en √n morceaux
	•	tu travailles morceau par morceau
	•	tu push vers B
	•	tu reconstruis A

Comment tu sais que c’est bien O(n√n)

Processus :
	•	tu fais √n étapes
	•	chaque étape traite environ n éléments
→ n × √n = n√n.

Exemple concret

Pour 100 éléments → √100 = 10 chunks
Pour 500 → √500 ≈ 22 chunks

Nombre d’actions attendu

100 nombres : ~800 à 2000
500 nombres : 5000 à 12000
(les bornes sont celles imposées dans le sujet, donc ça match parfaitement).
