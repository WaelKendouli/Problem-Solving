#include <iostream>
using namespace std;
void reader (float&  a, float& h)
{
cout << "  Triangle Area dimension  1 : \n";
cin >> a;
cout << "  Triangle Area dimension  2 : \n";
cin >> h;
}
float CalculateTriangleArea(float  a,float h)
{
    float Area = a / 2 * h;
    return Area;
}
void Results(float Area)
{
cout << " Area = " << Area;
}

int main()
{
    float  a , h;
    reader(a, h);
    Results(CalculateTriangleArea(a, h));
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
