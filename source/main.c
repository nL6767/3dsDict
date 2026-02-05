#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>




//defines for the math + logic stuff

#define LINES_PER_PAGE 30
#define MAX_PAGES 256  // arbitrary max, adjust if word list grows
#define STATIC_PAGES 2 // 0 = ASCII splash 1 = App info / credits
#define ASCII_LINES 30
#define ASCII_LINES_TWO 19


//define new type consisting of 2 unchanable char strings FR DE wordpairs has to be defined before the WordList comes
typedef struct {
    const char* french;
    const char* german;
} Word;




//Hardcoded worlist

Word WordList[] = {
		
        {"annuler", "abbrechen"},
        {"supprimer", "löschen"},
        {"aperçu", "Vorschau"},
        {"aléatoire", "zufällig"},
        {"par / fait par", "gemacht von"},
        {"trier", "sortieren"},
        {"installer des badges", "Bildschirmbadges/Bildschirmsticker installieren"},
        {"démarrer", "starten"},
        {"nouveau", "neu"},
        {"menu des splash", "Splashscreenmenu"},
        {"paramètres", "Einstellungen"},
        {"sans fil", "drahtlos"},
        {"luminosité", "Helligkeit"},
        {"sauvegarder", "sichern/speichern"},
        {"effacer", "löschen"},
        {"mettre à jour", "updaten/aktualisieren"},
        {"a partir de", "ab/von da an"},
        {"dossier", "Ordner"},
        {"le logiciel", "das Programm"},
        {"vitesse", "Geschwindigkeit"},
        {"écran tactile", "Touchscreen"},
        {"couper (ordi)", "unterbrechen/abbrechen"},
        {"mode veille", "Standbymodus"},
        {"réception de contenu", "Empfang von Inhalten"},
        {"podomètre", "Schrittzähler"},
        {"accumulation de jetons", "jetons sammeln"},
		{"écran supérieur", "oberer Bildschirm"},
		{"écran inférieur", "unterer Bildschirm"},
		{"dossier d'applications", "App-Ordner"},
		{"dossier", "Ordner"},
		{"mettre en pause", "pausieren"},
		{"reprendre", "fortsetzen"},
		{"lancer une application", "eine Anwendung öffnen"},
		{"fermer une application", "eine Anwendung schliessen"},
		{"logiciel en cours", "laufendes Programm"},
		{"quitter le logiciel", "Programm beenden"},
		{"écran d'accueil", "Startbildschirm"},
		{"paramètres de la console", "Systemeinstellungen"},
		{"paramètres Internet", "Internet-Einstellungen"},
		{"télécharger", "herunterladen"},
		{"point d'accès", "Zugangspunkt"},
		{"intensité du signal", "Signalstärke"},
		{"mode avion", "Flugmodus"},
		{"carte SD insérée", "SD-Karte eingelegt"},
		{"retirer la carte SD", "SD-Karte entfernen"},
		{"mémoire de la console", "Konsolenspeicher"},
		{"espace libre", "freier Speicherplatz"},
		{"gestion des données", "Datenverwaltung"},
		{"supprimer des données", "Daten löschen"},
		{"déplacer des données", "Daten verschieben"},
		{"données de sauvegarde", "Speicherdaten"},
		{"sauvegarde corrompue", "beschädigter Spielstand"},
		{"restaurer les données", "Daten wiederherstellen"},
		{"redémarrage nécessaire", "Neustart erforderlich"},
		{"mise à jour du système", "Systemupdate"},
		{"niveau de batterie", "Akkustand / Batteriezustand"},
		{"batterie faible", "niedriger Akkustand"},
		{"recharger la batterie", "die Batterie wieder aufladen"},
		{"adaptateur secteur", "Netzteil"},
		{"connexion au chargeur", "Verbindung zum Ladegerät"},
		{"message système", "Systemmeldung"},
		{"notification", "Benachrichtigung"},
		{"mise en veille automatique", "automatischer Ruhemodus"},
		{"réinitialiser la console", "Konsole zurücksetzen"},
		{"restaurer les paramètres d'usine", "Werkseinstellungen zurücksetzen"},
		{"communication locale", "lokale Kommunikation"},
		{"mettre en communication locale", "lokale Verbindung herstellen"},
		{"être l'hôte", "hosten"},
		{"échange de données", "Datenaustausch"},
		{"logiciel compatible", "kompatible Software"},
		{"logiciel non compatible", "inkompatible Software"},
		{"personnalisé", "benutzerdefiniert"},
		{"afficher la version du système", "Systemversion anzeigen"},
		{"afficher les informations système", "Systeminformationen anzeigen"},
		{"démarrage sécurisé", "sicherer Start"},
		{"mode de récupération", "Wiederherstellungsmodus"},
		{"fichier", "Datei"},
		{"extension de fichier", "Datenerweiterung"},
		{"élargissement", "Vergrösserung"},
		{"élargir", "erweitern"},
		{"accéder à", "aufrufen"},
		{"fichier corrompu", "beschädigte Datei"},
		{"gestionnaire de titres", "Titelmanager"},
		{"capture d'écran", "Screenshot / Bildschirmfoto"},
		{"enregistrer une capture", "Screenshot speichern"},
		{"enregistrement vidéo", "Videoaufnahme"},
		{"s'afficher", "darstellen/sich darstellen"},
		{"épingler", "anpinnen"},
		{"joindre un fichier", "eine Datei anhängen"},
		{"m Anhang finden Sie...", "Ci-joint / Vous trouverez en pièce jointe"},
		{"Fichier joint / pièce jointe", "Angehängte Datei"},
		{"Pièce jointe (f) / Appendice (m)", "Anhang"},
		{"Veuillez trouver ci-joint le document", "Bitte finden Sie das Dokument im Anhang"},
		{"Je vous envoie le fichier en pièce jointe", "Ich sende Ihnen die Datei im Anhang"},
		{"être affiché(e) électroniquement", "angezeigt werden"},
		{"pousser le bouton", "den Knopf drücken"},
		{"vers la droite", "nach/gegen rechts"},
		{"ajuster", "einstellen"},
		{"charger", "aufladen / laden"},
		{"connexion Internet", "Internetverbindung"},
		{"téléverser / envoyer", "hochladen"},
		{"mettre en mode veille", "in den Ruhezustand versetzen"},
		{"redémarrer", "neu starten"},
		{"profil utilisateur", "Benutzerprofil"},
		{"sauvegarde automatique", "automatische Speicherung"},
		{"menu principal", "Hauptmenü"},
		{"réseau", "Netzwerk"},
		{"réseau social", "soziales Netzwerk"},
		{"pare-feu", "Firewall"},
		{"mise à jour logicielle", "Softwareupdate"},
		{"un bug", "Bug/Fehler"},
		{"erreur", "Fehler"},
		{"Error", "Error"},
		{"correctif", "Patch"},
		{"interface utilisateur", "Benutzeroberfläche"},
		{"dispositif externe", "externes Gerät"},
		{"logiciel intrusif", "eindringende Software"},
		{"s'introduire", "eindringen"},
		{"logiciel du système", "System-Software"},
		{"cyber", "cyber-(prefix)"},
		{"cyberattaque", "Cyber-Attacke"},
		{"mémoire cache", "Cache-Speicher"},
		{"stockage en nuage", "Cloud-Speicher"},
		{"mot de passe complexe", "komplexes Passwort"},
		{"barre de recherche", "Suchleiste / Suchfeld"},
		{"branchement", "Anschluss (Geräte/Gas/Wasseranschluss)"},
		{"connexion", "Anschluss (Software / PC)"},
		{"fuite de données", "Datenleck"},
		{"données", "Daten"},
		{"flux de données", "Datenfluss"},
		{"transfert des données", "Datentransfer"},
		{"Traitement de données", "Datenverarbeitung"},
		{"Diagramme de flux de données", "Datenflussdiagramm (DFD)"},
		{"influx", "Zustrom"},
		{"décodeur de message", "Nachrichtenentschlüsseler"},
		{"capteur thermique", "Wärmesensor"},
		{"équipement d'espionnage", "Spionageausrüstung"},
		{"écoute électronique", "Abhörgerät / elektronische Überwachung"},
		{"camouflage optique", "optische Tarnung"},
		{"communication sécurisée", "sichere Kommunikation"},
		{"mission top-secrète", "streng geheime Mission"},
		{"hyperpropulsion", "Hyperantrieb"},
		{"gravité artificielle", "künstliche Schwerkraft"},
		{"source", "Quelle"},
		{"source sûre", "sichere Quelle"},
		{"code source", "Quellcode"},
		{"indication f des sources", "Quellenangabe"},
		{"origine", "Herkunft"},
		{"trajectoire", "Flugbahn"},
		{"vaisseau de reconnaissance", "Aufklärungsschiff"},
		{"drone de reconnaissance", "Aufklärungsdrohne"},
		{"système de navigation stellaire", "Sternennavigationssystem"},
		{"planète hostile", "feindlicher Planet"},
		{"spatial", "[Welt]räumlich"},
		{"espace", "Raum"},
		{"vaisseau spatial", "Raumschiff"},
		{"navire", "Schiff"},
		{"bateau", "Boot"},
		{"mitrailleuse f", "Maschinengewehr"},
		{"surveillance f", "Überwachung"},
		{"surveillance  f  électronique", "elektronische Überwachung"},
		{"mesure  f  sévère", "harte Massnahme"},
		{"être antidaté avec effet rétroactif au 1 er  avril", "soll rückwirkend zum 1. April gelten"},
		{"porte  f  de derrière", "Hintertüre / backdoor"},
		{"drapeau", "Flagge"},
		{"il flotte", "es schifft"},
		{"s'inscrire à", "sich anmelden"},
		{"enregistrer qc.", "registrieren"},
		{"coffrer qn.", "jmdn einbuchten"},
		{"route", "Strasse"},
		{"route aérienne/maritime", "Luft-/Seeweg m"},
		{"ligne  f  droite", "Luftlinie"},
		{"tout droit", "geradeaus"},
		{"circuit", "Rennstrecke"},
		{"espion / espionne", "Spion/Spionin"},
		{"agent secret / agente secrète", "Geheimagent"},
		{"mission secrète", "Geheimmission"},
		{"couverture", "Deckung"},
		{"infiltration f", "Unterwanderung"},
		{"une planque", "Versteck / Unterschlupf"},
		{"planquer qc", "etwas verstecken"},
		{"se planquer", "sich verstecken"},
		{"quartier général", "Hauptquartier"},
		{"remise f", "Übergabe"},
		{"emporter", "mitnehmen"},
		{"les services secrets", "Geheimdienst"},
		{"équipement", "Ausrüstung"},
		{"un gadget", "[praktisches] Gerät"},
		{"un dispositif", "Gerät/Vorrichtung"},
		{"dispositif antivol", "Diebstahlsicherung"},
		{"outil high-tech", "High-Tech-Werkzeug"},
		{"un équipement d’espionnage", "Spionageequipment"},
		{"un rouge à lèvres laser", "Laserlippenstift"},
		{"un bracelet-laser", "Laser-Armband"},
		{"un micro espion", "eine Wanze"},
		{"des bottes à réaction", "Raketenstiefel"},
		{"des lunettes infrarouges", "Infrarotbrille"},
		{"s'introduire", "eindringen"},
		{"système informatique", "Datenverarbeitungsanlage/Betriebssystem"},
		{"une ceinture multifonction", "ein Multifunktionsgürtel"},
		{"appareil  m  infrarouge", "Nachtsichtgerät"},
		{"vision nocturne m", "Nachtsicht"},
		{"concevoir", "auffassen / entwerfen / konzipieren"},
		{"une caméra miniature", "Minikamera"},
		{"camoufler", "tarnen"},
		{"se camoufler en qc", "sich als etw tarnen"},
		{"tenue  f  de camouflage", "Tarnanzug"},
		{"une combinaison furtive", "Tarnanzug"},
		{"furtif/furtive", "heimlich"},
		{"la cape d'invisibilité", "Tarnkappe"},
		{"[avion] bombardier  m  furtif", "Tarnkappenbomber"},
		{"avion  m  furtif", "Tarnkappenflugzeug"},
		{"opération", "Operation"},
		{"une montre-communicante", "Eine Uhr mit Kommunikationsfunktion"},
		{"un mot de passe", "Kennwort / Passwort"},
		{"un code d’accès", "ein Zugangscode"},
		{"un piège", "Falle"},
		{"un laboratoire secret", "Geheimlabor"},
		{"clé  f  USB", "USB-Stick"},
		{"clé", "Schlüssel"},
		{"clé  f  mémoire", "Speicherstick"},
		{"carte SD", "SD Karte"},
		{"vecteur", "Vektor"},
		{"une mousse immobilisante", "immobilisierender Schaum"},
		{"bâton", "Schlagstock"},
		{"un rayon paralysant", "ein lähmender Strahl"},
		{"Activation du gadget", "Aktivierung Ihres Geräts"},
		{"On est repérées!", "Wir werden entdeckt/sind aufgeflogen"},
		{"un filet électrifié", "ein elektrisches Netz"},
		{"un gaz soporifique", "Schlafgas"},
		{"Retrait stratégique", "strategischer Rückzug"},
		{"un savant fou / une savante folle", "ein verrückter Wissenschaftler"},
		{"réseau  m  local sans fil", "drahtloses lokales Netzwerk"},
		{"un décodeur", "Decoder"},
		{"un plan machiavélique", "ein hinterhältiger Plan"},
		{"des menottes intelligentes", "intelligente Handschellen"},
		{"des menottes", "Handschellen"},
		{"un brouilleur", "ein Störsender"},
		{"une base secrète", "Geheimbasis"},
		{"chiffrement m", "Verschlüsselung"},
		{"serpent", "Schlange"},
		{"un dispositif d’écoute", "ein Abhörgerät"},
		{"un piratage", "Hack / Hackangriff"},
		{"un drone espion", "eine Spionagedrohne"},
		{"un mouchard", "Spitzel / Wanze"},
		{"mouchard (appareil)", "elektronisches Aufzeichnungsgerät"},
		{"un traceur GPS", "ein GPS-Tracker"},
		{"unité spéciale", "Spezialeinheit"},
		{"infrarouge", "Infrarot"},
		{"rayonnement m", "Strahlung"},
		{"abandonné(e)", "verlassen"},
		{"l'espoir", "Hoffnung"},
		{"chanceux", "glück haben"},
		{"heureux", "glücklich/happy"},
		{"content", "zufrieden"},
		{"joyeux", "fröhlich"},
		{"la chance", "Glück"},
		{"bonheur", "Glück"},
		{"envole toi", "Flieg fort"},
		{"envoler", "wegfliegen"},
		{"disparaître", "verschwinden"},
		{"enlève toi", "verzieh dich"},
		{"enlever", "wegnehmen"},
		{"enlever qc de", "etwas entfernen von"},
		{"la terre", "die Erde"},
		{"s'accrocher à qc", "sich an etwas festklammern/festhalten"},
		{"fonce toi", "Stürze dich hinein!"},
		{"Perdu très loin de la Terre", "Verloren weit weg von der Erde"},
		{"Abandonnée sans repères", "Ausgesetzt ohne jegliche Orientierung"},
		{"Molly fonce sans te retourner!", "Molly stürz dich ins Abenteuer ohne dich umzusehen!"},
		{"Tout ce que as aimé le destin l'a emporté", "Alles was du geliebt hast hat dir das Schicksal weggenommen"},
		{"Pas cette fois, accroche-toi", "Diesmal nicht, halte durch"},
		{"Molly fonce, la chance va tourner!", "Molly stürmt voran, das Glück wird sich zu dir wenden!"},
		{"La vie s'ouvre devant toi.", "Das Leben öffnet sich vor dir."},
		{"Entends-tu ton cœur qui bat?", "Hörst du dein Herz, das schlägt?"},
		{"Tout les rêves sont permis.", "Alle Träume sind erlaubt."},
		{"Envole-toi vers l'infini!", "Flieg davon ins Unendliche!"},
		{"course intergalactique", "intergalaktische Rennen"},
		{"le Grand Prix d’Oban", "Der Große Preis von Oban"},
		{"un pilote / une pilote", "Pilot"},
		{"une écurie", "Rennstall/Team"},
		{"hangar", "hangar"},
		{"un concurrent / une concurrente", "Konkurrent"},
		{"un adversaire", "Gegner"},
		{"rival", "Rivale"},
		{"le départ", "Abfahrt/Abflug"},
		{"l’arrivée", "Ankunft"},
		{"le classement", "Platzierung / Ranking"},
		{"surchauffer", "überhitzen"},
		{"bruit", "Lärm/Geräusch"},
		{"argile", "Ton"},
		{"sans voix", "sprachlos"},
		{"doux/douce", "leise"},
		{"disqualification", "Disqualifizierung"},
		{"un vaisseau de course", "Rennschiff / Rennraumschiff (Oban)"},
		{"un engin spatial", "ein Raumfahrzeug"},
		{"l'engin", "Maschine"},
		{"moteur", "Motor"},
		{"un bolide", "Rennwagen"},
		{"le cockpit", "Cockpit"},
		{"la coque", "der Rumpf (vaisseau spatial /navire)"},
		{"les propulseurs", "die Antriebe / Triebwerk"},
		{"vitesse de la lumière f", "Lichtgeschwindigkeit"},
		{"dépasser la vitesse maximale [autorisée]", "die zulässige Höchstgeschwindigkeit überschreiten"},
		{"Propulsion à la vitesse de la lumière", "Lichtgeschwindigkeitsantrieb"},
		{"l'hyperespace", "Hyperraum"},
		{"propulsion hyperspatiale", "Hyperraumantrieb"},
		{"gicleur m", "Düse (Vergaser)"},
		{"tuyère f", "Düse a. LUFTF (Turbine)"},
		{"avion  m  à réaction", "Düsenflugzeug"},
		{"propulsion par réaction", "Düsenantrieb"},
		{"helicoptère", "Helikopter"},
		{"pale  f  de rotor", "Rotorblatt"},
		{"s'élever [dans les airs]", "aufsteigen"},
		{"plonger", "tauchen"},
		{"refaire surface", "auftauchen"},
		{"immerger qn/qc", "jdn/etw ins Wasser tauchen"},
		{"sous-marin", "U-boot"},
		{"sous-marin  m  nucléaire", "Atom-U-Boot"},
		{"équipage  m  d'un sous-marin", "U-Boot-Besatzung"},
		{"soutenir", "unterstützen"},
		{"appuyer", "drücken"},
		{"supporter", "ertragen"},
		{"les ailerons stabilisateurs", "Stabilisierungsflossen"},
		{"ailette", "Stabilisierungs-flügel"},
		{"aileron", "Heckflosse"},
		{"stabilisateur", "Stabilisator"},
		{"hydrodynamique", "hydrodynamisch"},
		{"aérodynamique", "aerodynamisch"},
		{"avoir des lignes aérodynamiques", "aerodynamisch geformt sein"},
		{"carte de navigation", "Navigationskarte"},
		{"système  m  de navigation [GPS]", "Navigationsgerät GPS"},
		{"erreur  f  de navigation", "Navigationsfehler"},
		{"salle  f  de navigation", "Navigationsraum"},
		{"navigateur  m  Web", "Navigationsprogramm"},
		{"logiciel", "Software"},
		{"logiciel  m  de reconnaissance optique de caractères", "OCR-Software"},
		{"logiciel  m  du système", "System-Software"},
		{"logiciel antivirus m", "Antivirus-Software"},
		{"progiciel m", "Softwarepaket"},
		{"application f", "App"},
		{"le tableau de bord", "Das Armaturenbrett"},
		{"paramétrer les commandes", "die Befehle einstellen"},
		{"basculer le levier de commande", "den Schalthebel umlegen"},
		{"les commandes", "Befehle"},
		{"carnet", "Heft"},
		{"prendre les commandes", "das Steuer übernehmen"},
		{"le moteur", "Motor"},
		{"Panneau de contrôle", "Kontrollpanel"},
		{"la poussée", "die Schubkraft"},
		{"la vitesse maximale", "die Höchstgeschwindigkeit"},
		{"la surchauffe", "die Überhitzung"},
		{"une panne", "Panne"},
		{"dysfonctionnement", "Fehlfunktion"},
		{"un système de propulsion avancé", "ein fortschrittliches Antriebssystem"},
		{"avancer", "vorrücken"},
		{"poursuivre", "fortfahren"},
		{"partir (véhicule)", "ab/wegfahren"},
		{"véhicule solaire", "Solarmobil"},
		{"véhicule utilitaire", "Nutzfahrzeug"},
		{"neurotransmetteur m", "Neurotransmitter"},
		{"amplificateur m", "Verstärker"},
		{"signal", "Signal"},
		{"langage informatique", "Computersprache"},
		{"binaire", "binär"},
		{"code binaire", "Binärcode"},
		{"système de numération binaire", "Binärsystem"},
		{"Zéro", "Null"},
		{"lavande", "Lavendel"},
		{"un module d’accélération", "ein Beschleunigungsmodul"},
		{"un bouclier énergétique", "Energieschild"},
		{"une surcharge moteur", "eine Motorüberlastung"},
		{"un stabilisateur gravitationnel", "ein Gravitationsstabilisator"},
		{"un amplificateur de puissance", "eine Leistungsverstärker"},
		{"l’espace profond", "Weltraum"},
		{"profond", "tief"},
		{"la cité", "die Stadt"},
		{"la ville", "die Stadt"},
		{"province", "Provinz"},
		{"Provence", "die Provence (FR)"},
		{"périphérie f", "umliegende Umgebung"},
		{"environs mpl", "Umgebung"},
		{"environnement m", "Umgebung"},
		{"environ", "ungefähr"},
		{"la moyenne", "Durchschnitt"},
		{"sillonner les mers", "das Meer durchschneiden Bug, Schiff"},
		{"bâbord", "Backbord"},
		{"tribord", "Steuerbord"},
		{"sous-marin(e)", "unterseeisch"},
		{"un champ d’astéroïdes", "Asteroidenfeld"},
		{"une nébuleuse", "Gasnebel (Astronomie)"},
		{"Nébuleuse d'Orion", "Orionnebel"},
		{"la gravité zéro", "Schwerelosigkeit"},
		{"une tempête cosmique", "kosmischer Sturm"},
		{"éclair", "Blitz"},
		{"courant m", "Strom"},
		{"être au courant", "auf dem Laufenden sein"},
		{"Mettre au courant", "Informieren / in Kenntnis setzen."},
		{"Se tenir au courant", "Sich auf dem Laufenden halten"},
		{"le permis", "Führerschein"},
		{"obtenir votre permis", "Führerschein machen/bekommen"},
		{"Permis de séjour", "Aufenthaltsbewilligung"},
		{"une planète hôte", "Gastgeberplanet"},
		{"une combinaison de pilote", "Pilotenanzug"},
		{"un casque de navigation", "ein Navigationshelm"},
		{"écran tactile", "Touchscreen"},
		{"affichage tête haute", "heads up display (HUD)"},
		{"mémoire  f  vive", "Arbeitsspeicher"},
		{"disque  m  dur", "Festplatte"},
		{"disque dur externe", "externe Festplatte"},
		{"lecteur  m  de/du disque dur", "Festplattenlaufwerk"},
		{"lecteur de disques", "Diskleser"},
		{"barre des tâches", "Task-Leiste"},
		{"un communicateur", "ein Kommunikator"},
		{"un mécanicien", "Mechaniker"},
		{"le staff technique", "das technische Personal"},
		{"le titre de champion", "der Meistertitel"},
		{"l’honneur", "Ehre"},
		{"la revanche", "Rache"},
		{"le destin", "Schicksal"},
		{"un enjeu colossal", "ein kolossales Unterfangen"},
		{"une trahison", "Verrat"},
		{"traître", "Verräter"},
		{"Préparez-vous au départ", "Machen sie sich zur Abfahrt bereit"},
		{"Pleine puissance !", "Volle Kraft!"},
		{"Les propulseurs ne tiennent plus !", "Die Triebwerke halten nicht mehr!"},
		{"On va droit dans le champ d’astéroïdes", "Wir steuern direkt ins Asteroidenfeld hinein."},
		{"Cette course décidera de tout", "Dieses Rennen wird alles entscheiden"},
		{"une espèce extraterrestre", "eine außerirdische Spezies"},
		{"conseil galactique", "intergalatischer Rat/Senat"},
		{"une alliance", "Allianz"},
		{"un héritage ancestral", "ein uraltes Erbe"},

    };




//structurecomment



const char* asciiArt[ASCII_LINES] = {
    "555?!J555555555555555555Y5555555555555555555?!Y55",
	"5555J^^?5555555555555555!J555555555555555Y7:~5555",
	"555555~ :7Y5555555555555.~5555555555555J~. ?55555",
	"5555555?  .~J555555555P? .Y5555555555?^  :Y555555",
	"55555555J.   :!J55555PY.  ^5555555J~.   ^55555555",
	"55YJJJY5P5:     :!?JJ7. :. :?JJ?~:     ~P55YJJJY5",
	"5YJ?!:..^?J.      .!~  7PJ  :7^       ^Y7^..^!?YY",
	"5555Y5J~  ..  :^  !P5. ?5Y  ?PY  .^:  .. .!Y55555",
	"555~ J5P7    :5P~ !P5. ..:  ?PY  ?PJ    .YP5^:555",
	"55J ^5555.   :5P~ !P5. ~Y7  JPY  ?PY    ^P557 755",
	"5P! J555!    :5P~ !P5. ?PY  ^?~  ?PY     ?55Y :55",
	"55^ Y55Y??5!.:5P~ !P5. :JY  .^:  ?PY :7???555:.55",
	"55~ J555555P^.55~  ^:    .  ?PY  ?PY 7P555555..55",
	"55? !P55555! :55~ :?!  7?.  ?PY  ?PY .?55555? ~55",
	"555: Y555J:  :55~ !P5. ?PY  ?PY  ?PY   ~Y555^ Y55",
	"555J75Y?:    :5P! !55. ^?!  ?PY  JPY     ~?5JJ555",
	"55555Y7!!~~^:.??: !P5. :.:  JPY  ~J!.:^~!!!?55555",
	"5555555??5P55Y?~. ~Y?. J5Y  !Y7  .!?Y5P5J?Y555555",
	"5555555?:.!Y5P55Y~     75J      75PP557:.75555555",
	"555555555?^.^7J555~     :.     7P5Y7^:^7555555555",
	"55555555555Y7~::?PY ^7^    ~7.:55!:^7Y55555555555",
	"555555555555555JY55 :J5:  !5? ^55YY55555555555555",
	"555555555555555555Y!~^.    :^~7555555555555555555",
	"5555555555555555555555Y! .7Y555555555555555555555",
	"5555555555555555555555555555555555555555555555555",
	"5555555555555555555555555555555555555555555555555",
	"5555555555555555555555555555555555555555555555555",
	"5555555555555555555555555555555555555555555555555",
	"5555555555555555555555555555555555555555555555555",
	"5555555555555555555555555555555555555555555555555",
	// ...
};

const char* asciiArt2[ASCII_LINES_TWO] = {
	"        .................................         ",
	"     .?5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5Y!      ",
	"     5#BBBBBBBBBBBBBBBBBBBBBBBGGGGGBBBGGGGB#!     ",
	"     P############BBBBBBBB#P?^:::::~?GBBBGG#?     ",
	"     P########BBBBBBBBBBBB7  !Y5P5J^ .JBGGB#?     ",
	"     P######BBBBBBBBBBBBB7 .5BBBBBBBJ  JBGB#?     ",
	"     P###BBBBBBBBBBBBBBB5  7BBBBGGGGB7 :GB##?     ",
	"     P#BBBBBBBBBBBBBBBBBY::5BBGGGGGGG5:^G###?     ",
	"     P#BBBG^::::::::::::::::~GGGGGGGBBB#####?     ",
	"     P#BBBP                 :BBBBB##########?     ",
	"     P#BBBP       JGP!      :BBBBBBB########?     ",
	"     P#BBBP       ?#B~      :BBBBBBBBBBBBB##?     ",
	"     PBBBBP       ^#B:      :BBBBBBBBBBBBBB#?     ",
	"     PBBBB5       !P5~      :GBBBBBBBBBBBBB#?     ",
	"     PBBBBP:                ~GGGGBBBBBBBBBB#?     ",
	"     PBBBBBP?!~~~~~~~~~^~~!?PGGGGGGGBBBBBBB#?     ",
	"     PBBBGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBB#7     ",
	"      PYGBBBGGGGGGGGGGGGGGGGGGGGGGGGGBBBB#!       ",
	"       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         ",
};





//structurecomment



// Function to estimate how many console lines a word pair will take
int countLines(const Word* w) {
    int frenchLen = strlen(w->french);
    int germanLen = strlen(w->german);

    // 3DS top screen is 30 characters wide per line
    int charsPerLine = 50;

    int lines = (frenchLen + charsPerLine - 1) / charsPerLine;
    lines += (germanLen + charsPerLine - 1) / charsPerLine;

    lines += 1; // extra blank line for formatting
    return lines;
}

//main function 


int main(int argc, char* argv[]) {
    gfxInitDefault();

    // Create two separate consoles
    PrintConsole topScreen, bottomScreen;
    consoleInit(GFX_TOP, &topScreen);
    consoleInit(GFX_BOTTOM, &bottomScreen);

    const char* author = "nLggercatgirl67";
    const char* AppInfo = "Dictionary for 3DS words in French including words I find useful\n";
    const char* AccessDict = "press A to access dictionary";

    int WordCount = sizeof(WordList) / sizeof(WordList[0]);

    // --- Build page start indices dynamically ---
    int dictPageStart[MAX_PAGES];
	int dictPages = 0;
	int lineCounter = 0;
	
	dictPageStart[0] = 0; // first dictionary page index will be 0 (after front page)
	
    
    
    
    for (int i = 0; i < WordCount; i++) {
        int linesNeeded = countLines(&WordList[i]);

        if (lineCounter + linesNeeded > LINES_PER_PAGE) {
            // start a new page
			dictPages++;
            dictPageStart[dictPages] = i;
            lineCounter = 0;
        }

        lineCounter += linesNeeded;
    }
	dictPages++;
	
	int totalPages = STATIC_PAGES + dictPages; // front page counts as page 0

    int page = 0;
    int lastPage = -1; // forces first draw

    // ---- Draw static bottom screen once ----
    consoleSelect(&bottomScreen);
    consoleClear();
    printf("Navigation\n\n");
    printf("A = Next page\n");
    printf("B = Previous page\n");
    printf("START = Exit\n\n\n");
    printf("Page %d / %d\n", page + 1, totalPages);

    while (aptMainLoop()) {
        gspWaitForVBlank();
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START)
            break;
		
		//kDown = KeyPressedDetection
		//KEY = Pressed key

        if (kDown & KEY_A && page < totalPages - 1)
            page++;
        if (kDown & KEY_B && page > 0)
            page--;

        if (page != lastPage) {
            lastPage = page;

            // ----- Update bottom screen -----
            consoleSelect(&bottomScreen);
            consoleClear();
            printf("Navigation\n\n");
            printf("A = Next page\n");
            printf("B = Previous page\n");
            printf("START = Exit\n\n");
            printf("Page %d / %d\n", page + 1, totalPages);
			
			
			
			

            // ----- Top screen -----
			
			
			
            consoleSelect(&topScreen);
            consoleClear();

            if (page == 0) {
				 // ASCII splash
				 for (int i = 0; i < ASCII_LINES; i++)
					 printf("%s\n", asciiArt[i]);
			}
			
                
			else if (page == 1) {	
				
				
				// Front page
                printf("3DS French Cyber-Dictionary\n");
                printf("by %s\n\n", author);
                printf("%s\n\n", AppInfo);
                printf("%s\n\n", AccessDict);
				
				//print unlock_Ascii
				for (int i = 0; i < ASCII_LINES_TWO; i++)
					printf("%s\n", asciiArt2[i]);
			}
            else {
                // Dictionary pages
				int dictPage = page - STATIC_PAGES;
				
                int startIndex = dictPageStart[dictPage];
                int endIndex = (dictPage + 1 < dictPages) ? dictPageStart[dictPage + 1] : WordCount;

                for (int i = startIndex; i < endIndex; i++) {
                    printf("%s - %s\n\n", WordList[i].french, WordList[i].german);
                }
            }
        }

        gfxSwapBuffers();
    }

    gfxExit();
    return 0;
}
