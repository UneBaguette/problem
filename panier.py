t = 0.0


def main():
    # Le programme débute avec un texte qui résume tout du programme
    print("Programme qui calcul le total d'articles que vous avez et vous donne un reçu")
    print("Ajouter un article pour votre panier")
    ask()  # appelle la fonction ask


def ask():
    global m
    while m is not int:
        try:
            m = int(input("Combien d'articles voulez vous ajouter à votre panier ? Limite : 25 : "))
            if m <= 25:  # si m est plus petit ou égale à 25
                panier()
                break
            elif m >= 25:  # si m est plus grand ou égale à 25
                print("LIMITER A 25 ARTICLES !")
                ask()  # renvoie à la fonction ask
        except ValueError:
            print('! FORMAT INVALIDE !')


def panier():
    global t
    global m
    # On ouvre un fichier CSV
    file = open("reçu.txt", "a")
    # Enregistre dans le fichier
    file.write(f"Vous avez {m} d'article(s)")
    # boucle qui demande tant que l'utilisateur à terminer d'écrire ses articles et le prix
    for x in range(m):
        a = input(f"Article {x + 1} : ")
        p = float(input(f"Prix (HT) du produit en euro : "))
        t += p
        file.write(f"Article {x + 1} : {a}\nPrix de l'article (HT) : {p} €\n")
        file.write(f"TVA : {p * 0.2}\n")
        file.write("\n")
    ttc = t * 0.2
    print(f"Vous avez {m} articles dans votre panier")
    file.write(f"Montant HT : {t} €")
    file.write(f"\n")
    file.write(f"Montant total TTC : {ttc + t} €")
    print("Tout a été inscrit dans le reçu !")
    file.close()  # ferme le fichier à la fin


m = ''

main()
