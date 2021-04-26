# Grundlagen
-  Belegungsmengen, Wertetabellen, schaltalgebraisch Ausdrücke
-  partielle, nichtdeterminierte Funktionen (h-stern, h-punkt und g-Parameter)
-  Lösung impliziter Gleichungen
-  Werteverlaufsgleichheit bezüglich h-stern, bzw. h-punkt
-  Minimierungsverfahren (Karnaugh, Quine-McCluskey, Kazakov)
-  Hasards (Klassifikation, Erkennung, Vermeidung)
-  partielle, nichtdeterminierte Automatenfunktionen
-  Struktursynthese und ~analyse sequentieller Automaten, Vollständigkeit, Widerspruchsfreiheit
-  Flip-Flops(Typen, Eigenschaften, Ansteuergleichungen)
-  Zustandskodierung von Automaten
-  Kombinatorischer Schaltungen
-  Sequentielle Schaltungen
-  Partielle, nichtdeterminierte Funktionen
    -  Partielle Funktionen
      -  Anwendung bei der Minimierung
      -  Verallgemeinerte Wertverlaufsgleichheit
    -  Nichtdeterminierte Funktionen
-  Implizite Gleichungen
-  Minimierung partieller Boolescher Funktionen

# Normalformen
KNF (Kanonische Normalen Form): Zeilen mit 0 sind Output, alles was in den outputzeilen positiv ist negieren ()

DNF (Disjunkte Normalen Form): Zeilen mit 1 sind Output, alles was in den outputzielen negatic ist negieren

KDNF, KKNF, KNANF und KNONF

# Minimierungsarten
- Minimierung nach Karnaugh
- Minimierung nach Quine/McCluskey
- Minimierung nach Kasakov

# Flip Flops
JK-FLip-Flop: $Q:= J\bar{Q} \vee \bar{K}Q$ mit JK:="Toggle"

RS-Flip-Flop: $Q:=S\bar{Q} \vee \bar{R}Q$ ohne "toggle"

D-Flip-Flop: $Q:=D$ ohne "toggeln/speichern"


# Klausurvorbereitung
-  Strukturbeschreibung
    -  Analyse kombinatorischer Schaltungen
-  Dynamische Effekte - Hasards
    -  Funktions-Hasards
    -  Struktur-Hasards
    -  Funktionsbeschreibung sequentieller Schaltungen
-  Partielle, nichtdeterminierte Automaten
    -  Partielle Automaten
    -  Nichtdeterminierte Automaten
    -  Vollständigkeit, Widerspruchsfreiheit
    -  Synthese sequentieller Schaltungen
-  Flip-Flops
    -  Asynchrones Basis-Flip-Flop (RS-Flip-Flop)
    -  Charakteristische Gleichung, Schaltfolgetabelle
    -  Taktgesteuerte (synchrone) Flip-Flops
    -  Typische Vertreter
-  Struktursynthese
    -  Ermittlung der Ansteuergleichungen über Koeffizientenvergleich aus der charakteristischen Gleichung
    -  Ermittlung der Ansteuergleichungen durch direktes Auslesen aus dem Automatengraphen
    -  Gegenüberstellung der beiden Verfahren
    -  Parallele Automaten
-  Parallelität
-  Ausgabezuordnung