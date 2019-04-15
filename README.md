# Snake

Pout tester cette application, il est nécessaire de la compiler pour votre système d'exploitation.
On vous propose ici une compilation avec Microsoft Visual Studio pour Windows.

## Compilation avec microsoft Visual Studio pour Windows

Étape 1 : Avoir une version à jour de [Microsoft Visual Studio](https://visualstudio.microsoft.com/fr/vs/).

Étape 2 : Installer la dernière version de [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/index-fr.php).
> Attention, nous vous recommandons d'installer SFML directement à la racine de votre système d'exploitation (```C:\SFML-2.5.1\``` par exemple) !
Librairie supplementaire à lier -> linker -> entry  : **sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib**. Il est important d'utiliser les libraries de debug *-d* pour que le build debug ce fasse corectement.
[Linkers](https://www.sfml-dev.org/tutorials/2.5/images/start-vc-link-libs.png)


Étape 4 : Checkout ou cloner le projet depuis le [repository](https://github.com/MyGg29/ProjetCpp2).

Étape 6 : Importer le projet dans votre IDE
```Fichier -> Ouvrir -> Projet/Solution...``` et choisir l'emplacement du projet.

Étape 7 : Indiquer l'emplacement de SFML dans votre IDE


![Screenshot2](https://www.sfml-dev.org/tutorials/2.5/images/start-vc-paths.png)

Étape 8 : Compile, run and have fun ! ![smiley](https://cdn3.iconfinder.com/data/icons/developperss/PNG/Smiley.png)

Si vous rencontrez un problème avec SFML, reportez vous à la [documentation](https://www.sfml-dev.org/tutorials/2.5/start-vc-fr.php).
