# Raytracer2

Le Raytracer2 est un projet Epitech consistant au développement d'un moteur graphique 3D utilisant la technique du Raytracing, uniquement à l'aide du langage C et de la librairie [CSFML](https://www.sfml-dev.org/download/csfml/index-fr.php).

## Prérequis

Pour utiliser ce programme, vous devez être sur un système Linux et avoir installé la librairie CSFML.

## Installer le programme

Après avoir cloné le projet, exécutez les commandes suivantes:

```
cd Raytracer2
make
```

Une fois le programme installé, lancez-le avec la commande:

```
./raytracer2 [CONF_FILE] [SETTINGS_FILE] [SIZE_X] [SIZE_Y]
```

* [CONF_FILE]: Fichier de configuration contenant les objets à afficher ainsi que plusieurs paramètres (voir les fichiers *.conf* du dossier **ressources/**).

* [SETTINGS_FILE]: Fichier d'option contenant les différentes qualités d'affichages utilisables par les fichiers de configuration (voir les fichiers *settings* et *settings2* du dossier **ressources/**).

* [SIZE_X]: Taille en largeur de la fenêtre.

* [SIZE_Y]: Taille en hauteur de la fenêtre.


## Fonctionnalités

* Moteur 3D complet
* Déplacement dans l'espace
* Formes géomètriques variées (sphères, cylindres, cônes, cubes...)
* Images de fond
* Musiques
* Objets entièrements personnalisables (forme, couleur, poisition, poids, taille, lumière, matériaux)
* Moteur physique (suivant la loi universelle de la gravitation d'*Isaac Newton*)
* Fichiers de configuration (avec système d'héritage entre les objets)
* Fichiers d'option (augmentation ou diminution de la qualité pour s'adapter aux performances de la machine)
* Système de *Rendering* permettant de précalculer une scène pendant un temps défini pour un résultat encore plus fluide
* Jeu d'échecs jouable et complet
* Réflexion et réfraction de la lumière
* Textures applicables aux objets (dont des textures avec du relief)
* Système de luminosité et d'ombres cumulables
* Lecture des fichiers Windows BitMaP

## Vidéo
[![Voir la vidéo](https://img.youtube.com/vi/ioyE9032myY/0.jpg)](https://www.youtube.com/watch?v=ioyE9032myY)

## Auteurs

* [Lucas Le Ray](https://github.com/LucasLeRay)
* Olivier Telouk
* Yanis Aba
* Thery Fouchter
