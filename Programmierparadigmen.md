# Programmierparadigmen

## Was ist ein Paradigma?
- Paradigma – aus dem Altgriechischen Beispiel, Muster; Erzählung mit beispielhaftem Charakter (laut Duden)
- Programmierparadigmen beschreiben grundsätzliche Arten wie Computer-Programme formuliert werden können
- Programmiersprachen können einzelne oder viele Konzepte aufgreifen
  - Keine verbreitete Sprache greift alle behandelten Konzepte auf
  - Betrachtung unterschiedlicher Sprachen
- Ziel der Veranstaltung: Weiten der in Algorithmen und Programmierung eingeführten Sichten hin zu einem Werkzeugkoffer zur Lösung realer Probleme...

## Warum unterschiedliche Paradigmen?
Komplexität von Software schlecht beherrschbar

## Was bedeutet das?
- Programmierer schreiben, testen und dokumentieren zwischen 325 und 750 Codezeilen pro Monat
  - maximal 360.000 Zeilen in 40 Jahren!
- Komplexität muss verborgen werden, z.B. durch
  - Kapselung
  - Spezifische Spachkonstrukte, Domain Specific Languages
  - Ausdrucksstärkere Sprachen
- Entwicklung neuer Programmierparadigmen hilft Grenzen (ein wenig) zu verschieben
- Theoretische Rahmenbedingungen (Turing-Mächtigkeit, Satz von Rice) behalten Gültigkeit!

## Welche Paradigmen existieren?
- Aus Vorlesung AuP:
  - Imperative Algorithmen
  - Applikative Algorithmen
  - Deduktive Algorithmen
- Aber Vielzahl weiterer Formen
  - teilweise ergänzend, unterschiedliche Kategorisierung möglich
  - Bsp: prozedural, deklarativ, objekt-orientiert, datenstromorientiert, parallele & verteilte Programmierung...
- Teilweise unterschiedliche Bezeichnungen
  - Applikativ bzw. Funktional
  - Deduktiv bzw. Logisch
- Aktueller Trend: Multiparadigmen-Sprachen
  - Umsetzung unterschiedlichster Paradigmen in einer Sprache
  - Beispiele: Scala, neuere C++-Standards, ...

# Objektorientierung und weiterführende Konzepte am Beispiel Java
- Bekannt:
  - Grundlegendes Verständnis von Java
  - Kapselung durch Klassen und Vererbung
- Ziele:
  - Verständnis der Probleme bei Vererbung und Typersetzbarkeit in objektorientierten Programmiersprachen
  - Kennenlernen der Grundideen generischer und abstrahierender Konzepte in Objekt-orientierter Programmierung (OOP)
  - Praktische Erfahrungen anhand von Java & C++
- Ausdrucksstärke erhöhen, Komplexität verbergen

## Unit Testing
### Motivation
- Große Software-Systeme entwickeln sich über lange Zeiträume
- Wie können Änderungen an komplexen Code-Basen beherrscht werden?
- Veränderung über Zeit + Komplexität der Software
  - Änderungen führen mglw. zu Auswirkungen, die für Einzelne nicht immer überschaubar sind
  - Software muss nach Änderung von Grund auf durchgetestet werden
- Verbreitetes Vorgehen: zusätzlichen Code schreiben, der eigentlichen Code automatisch “überprüft”
  - Nicht vollständig möglich (z.B. Halteproblem)
  - Eher Heuristik
- Test-Code wird bei Ereignissen oder periodisch ausgeführt
  - Vor Releases, nach Commit in Repository, während der Entwicklung ...

### Eigenschaften von Unit-Tests
- Software schlecht als Ganzes testbar -> Zergliederung von Software in sinnvolle Einheiten
- Individuelle Tests dieser Einheiten
- Dabei: reproduzierbar & vollautomatisierbar
  - Ziel: Wann immer Änderungen in komplexen Programmen vorgenommen werden, möglichst vollständiger Test, da Programmierer nicht mehr alles überblicken
- Messung der Vollständigkeit der Tests schwierig
- Üblich: Messung von Überdeckung (Coverage) in Bezug auf Anzahl Funktionen, Code-Zeilen oder Verzweigungen
- Gute Praxis: Wenn ein Bug beim Testen oder Live-Betrieb auftritt -> Schreiben eines zusätzlichen Tests, um Wiederauftreten zu erkennen

### Unit-Testing in Java
- De facto Standard: JUnit Framework
- „Best Practice” für einfachen Einsatz:
  - Java Code in ein oder mehrere Klassen im Ordner src speichern
  - Im Ordner tests jeweils eine Klasse anlegen, die Funktionen einer Implementierungsklasse prüft
  - Konvention: Testklasse einer Klasse Name heißt NameTest
  - Eigentliche Tests werden in Methoden implementiert, die als Tests annotiert sind
  - Typischer Ansatz: für bekannte Werte ausführen und Ergebnis mit Grundwahrheit (erwartetes Verhalten) vergleichen, bspw. mit assertEquals-Funktion
- Viele weitere Features, z.B. Deaktivieren von Tests, Timeouts, GUI Coverage, Mocks

### Unit Testing – Richtiges Abstraktionsniveau
- Um die Tests auszuführen, müssen jeweils entsprechende Hauptprogramme generiert werden („Test Suites“)
- Hauptschwierigkeiten von Unit-Tests:
  - Richtiges Abstraktionsniveau
  - „Herauslösen“ von zu testendem Code aus Umgebung
- Zwei wesentliche Möglichkeiten:
  1. Individuelles Testen von Klassen:
    - Vernachlässigt Zusammenspiel zwischen Klassen
    - Oft sehr aufwändig, da andere Klassen für Unit-Tests nachgebildet werden müssen (Mocks)
    - Was bei zyklischen Abhängigkeiten?
  2. Gemeinsames Testen von Klassen:
    - Erfordert Eingreifen in gekapselte Funktionalitäten
    - Private & Protected Member-Variablen & Methoden!
    - Eigentlich nicht möglich?!

## Reflections
- Normaler Ablauf: Programm schreiben, compilieren, ausführen
  - Aber was wenn ich ein Programm zur Laufzeit inspizieren oder verändern möchte?
- Unterschiedliche Gründe
  - Testen (um Fehler zu injizieren!)
  - Fehlersuche („Debugging“)
  - Nachladen von Plugins zur Modularisierung von Programmen
  - Serialisierung/Deserialisierung von Code
  - „Patchen“ zur Laufzeit
  - Erkunden der Ablaufumgebung (z.B. OS-/Shared-Library Version)
- Benötigt die Fähigkeit, im Programm Codestruktur zu analysieren und ggf. zu verändern:
  - Typisch: Abruf Klassenhierarchie, Auflisten von Methoden und Parametern, Austausch von Klassen und Methoden
  - Teil von Java, Python, ...

API verstreut über verschiedene Packages, z.B. java.lang.Class, java.lang.instrument, java.lang.reflect

```java
Class cls = "test".getClass();
System.out.println("Die Klasse heisst " + cls.getName());
// Die Klasse heisst java.lang.String
```
```java
// import java.lang.reflect.Method;
Method[] methods = cls.getMethods();
for (Method m : methods)
System.out.println(m.getName());
```
### Annotationen
- Annotationen erlauben Anmerkungen an Klassen & Methoden
- Beginnen mit @
- Einige wenige vordefinierte z.B. @Override
- Aber auch eigene; u.a. durch Reflections abrufbar
- Häufig genutzt, wenn zusätzlicher Code geladen wird (Java EE)
- Oder um Unit-Tests zu markieren...
```java
class MultiTest {
  @org.junit.jupiter.api.Test
  void mul() {
    ...
```

### Reflektionen über Reflections
- Reflections sind ein sehr mächtiges Werkzeug, aber Einsatz sollte wohldosiert erfolgen
- Nachteile:
  - Geringe Geschwindigkeit weil Zugriff über Programmcode erfolgt
  - Kapselung kann umgangen werden
    - private, protected und final können entfernt werden
    - Aufruf/Veränderung interner Methoden & Auslesen/Veränderung interner Variablen
    - Synchronisation zwischen externen und internen Komponenten bei Weiterentwicklung?
  - Debugging veränderter Programme?
  - Sicherheit?!
- Verwandte Techniken:
  - Monkey Patching (JavaScript-Umfeld)
  - Method Swizzling (Swift/Objective-C-Umfeld)


## Assertions
- Kann man interne Zustände testen, ohne invasive Techniken wie Reflections?
- Einfache Möglichkeit: An sinnvollen Stellen im Programmcode testen, ob Annahmen/Zusicherungen (Assertions) stimmen...
- Tests, die nie falsch sein sollten
  - Erlauben gezielten Programmabbruch, um Folgefehler zu vermeiden
  - Erlauben gezieltes Beheben von Fehlern
  - Gemeinsames Entwickeln von Annahmen und Code
```java
class Stack {
  public void push(Object o) {
    ...
    if(empty() == true) // es sollte ein Objekt da sein
      System.exit(-1);
  }
  ...
}
```

Aber: Ausführungsgeschwindigkeit niedriger
- Zeitverlust stark abhängig von Programm/Programmiersprache
- Verbreitetes Vorgehen:
  - Aktivieren der Tests in UnitTests und Debug-Versionen
  - Deaktivieren in Releases
  - Benötigt spezielle „if“-Bedingung: assert
- Aktivierung der Tests über Start mit java -ea
```java
class Stack {
  public void push(Object o) {
    ...
    assert empty() == false
}
```

### Welche braucht man?
- Woran erkennt man beim Programmieren bzw. (erneutem) Lesen von Code, dass man eine Assertion hinzufügen sollte?
- Eine einfache Heuristik – Die „Eigentlich“-Regel:
  - Wenn einem beim Lesen von Programmcode ein Gedanke der Art „Eigentlich müsste an dieser Stelle XY gelten“ durch den Kopf geht,
  - dann sofort eine entsprechende Assertion formulieren!

### Spezielle Assertions: Pre- & Postconditions
- An welchen Stellen ist es sinnvoll, Annahmen zu prüfen?
- Einfache Antwort: an so vielen Stellen wie möglich
- Komplexere Antwort: Design by contract, ursprünglich Eiffel
- Methoden/Programmabschnitte testen Bedingung vor und nach Ausführung
- Einige Sprachen bieten spezialisierte Befehle: requires und ensures
-> Ziel mancher Sprachen: Formale Aussagen über Korrektheit

```java
class Stack {
  public void push(Object o) {
    assert o != null // precondition
    ...
    assert empty() == false // postcondition
  }
  ...
}
```

### Klasseninvarianten
- Bei OO-Programmierung sind Vor- und Nachbedingungen nur eingeschränkt sinnvoll
- Bedingungen oft besser auf Objekt-Ebene -> interner Zustand
- Invarianten spezifizieren Prüfbedingungen
- In Java nicht nativ unterstützt:
  - Erweiterungen, wie Java Modeling Language
  - Simulation:
```java
class Stack {
  void isValid() {
    for(Object o : _objs) // Achtung: O(n) Aufwand!
      assert o != null
  }
  public void push(Object o) {
    isValid() // always call invariant
    ...
    isValid() // always call invariant
}
```

## Exeptions
Signifikantes Element vieler Sprachen: Wie wird mit Fehlern umgegangen?
Fehler können unterschiedliche Gründe haben
Besser für Code-Komplexität: Fehlerprüfungen an zentralerer Stelle
- Abbrechen und Programm-Stack „abbauen“ bis (zentrale) Fehlerbehandlung greift
- Dabei Fehler sinnvoll gruppieren
- Java (und viele mehr): try/catch/throw-Konstrukt
```java
private void readFile(String f) {
  try {
      Path file = Paths.get("/tmp/file");
      if(Files.exists(file) == false)
        throw new IOException("No such dir");
      array = Files.readAllBytes(file);
  } catch(IOException e) {
      // do something about it
  }
}
```
throw übergibt ein Objekt vom Typ Throwable an Handler, dabei zwei Unterarten:
- Error: Sollte nicht abgefangen werden z.B. Fehler im Byte-Code, Fehlgeschlagene Assertions
- Exceptions:
  - Checked Exception: Programm muss Exception fangen oder in Methode vermerken
  - Runtime Exceptions: Müssen nicht (aber sollten) explizit behandelt werden, bspw. ArithmeticException oder IndexOutOfBoundsException

### Checked Exceptions
Deklaration einer überprüften Exception:
```java
  void dangerousFunction() throws IOException {
    ...
    if(onFire)
      throw IOException("Already burns");
    ...
}
```
Die Deklaration mit "throws IOException" lässt beim build mögliche Fehler durch IOExceptions dieser Funktion zu, diese müssen durch die aufrufende Methode abgefangen werden.
Aufrufe ohne try-catch-Block schlagen fehl!
Sollte man checked oder unchecked Exceptions verwenden?
- Checked sind potenziell sicherer
- Unchecked machen Methoden lesbarer
- Faustregel unchecked, wenn immer auftreten können (zu wenig Speicher, Division durch 0)

Abfangen mehrerer unterschiedlicher Exceptions
```java
try {
  dangerousFunction();
} catch(IOException i) {
  // handle that nasty error
} catch(Exception e) {
  // handle all other exceptions
}
```
Aufräumen nach einem try-catch-Block: Anweisungen im finally-Block werden immer ausgeführt, d.h. auch bei
return in try- oder catch-Block (oder fehlerloser Ausführung)
```java
try {
  dangerousFunction();
} catch(Exception e) {
  // handle exceptions
  return;
} finally {
  // release locks etc..
}
```


## Generizät von Datentypen
(Typ-)Generizität: 
- Anwendung einer Implementierung auf verschiedene Datentypen
- Parametrisierung eines Software-Elementes (Methode, Datenstruktur, Klasse, ...) durch einen oder mehrere Typen
Beispiel:
```java
int min(int a, int b) {
  return a < b ? a : b;
}
float min(float a, float b) {
  return a < b ? a : b;
}
String min(String a, String b) { // lexikographisch
  return a.compareTo(b) < 0 ? a : b;
}
```

### Grenzen von Typsubstitution
Problem: Für jeden Typ? Wie kann sort implementiert werden?
Möglicher Ausweg: Klassenhierarchie mit zentraler Basisklasse
```java
void sort(Object[] feld) { ... }            //z.B. java.lang.Object
void sort(java.util.Vector feld) { ... }    //alternativ (nutzt intern Object)
```
Möglicher Ausweg 2: Nutzung primitiver Datentypen nicht direkt möglich
```java
Object[] feld = new Object[10];         //Object[] ≠ int[]
feld[0] = new Integer(42);
int i = ((Integer) feld[0]).intValue(); //erfordert Wrapper-Klassen wie java.lang.Integer
```

Weiteres Problem: Typsicherheit<br/>
Typ-Substituierbarkeit: Kann ein Objekt einer Oberklasse (eines Typs) durch ein Objekt seiner Unterklasse (Subtyps) ersetzt werden?
Beispiel (isSubtyp): short $\rightarrow$ int $\rightarrow$ long 
Viele Programmiersprachen ersetzen Typen automatisch, d.h. diese wird auch für shorts und ints verwendet
```java
long min(long a, long b) {
  return a < b ? a : b;
}
```

Kreis-Ellipse-Problem: Modellierung von Vererbungsbeziehungen
- „Ist ein Kreis eine Ellipse?“ „Oder eine Ellipse ein Kreis?“
- Annahme: Kreis := Ellipse mit Höhe = Breite
```java
Circle c = new Circle();  
c.skaliereX(2.0);       //skalieren aus Klasse Circle
c.skaliereY(.5);        //is das noch ein Kreis?
```
evtl. Reihenfolge in der Klassenhierarchie tauschen (nutzung von Radius)? Was bedeutet das für Ellipse?
Verwandte Probleme: Rechteck-Quadrat, Set-Bag

### Ko- und Kontravarianz
Geg.: Ordnung von Datentypen von spezifisch $\rightarrow$ allgemeiner
- Gleichzeitige Betrachtung einer Klassenhierarchie, die Datentypen verwendet
- Kovarianz: Erhaltung der Ordnung der Typen
- Kontravarianz: Umkehrung der Ordnung
- Invarianz: keines von beiden
- Anwendung für
  - Parameter
  - Rückgabetypen
  - Ausnahmetypen
  - Generische Datenstrukturen

Beispiel: Basierend auf Meyer‘s SKIER-Szenario
```java
class Student {
  String name;
  Student mate;
  void setRoomMate(Student s) { ... }
}
```
Wie überschreibt man in einer Unterklasse Girl oder Boy die Methode „setRoomMate“ in elternfreundlicher Weise? Von Eltern sicher gewollt - Kovarianz:
```java
class Boy extends Student {
  void setRoomMate(Boy b) { ... }
}
class Girl extends Student {
  void setRoomMate(Girl g) { ... }
}
```
Was passiert mit folgendem Code?
```java
Boy kevin = new Boy("Kevin");
Girl vivian = new Girl("Vivian");
kevin.setRoomMate(vivian);
```
- Verwendet setRoomMate der Basisklasse
- setRoomMate Methoden der abgeleiteten Klassen überladen nur Spezialfälle $\rightarrow$ gültig

- In C++ und Java keine Einschränkung der Typen zur Compile-Zeit
- Kovarianz so nur in wenigen Sprachen implementiert (z.B. Eiffel über redefine); Überprüfung auch nicht immer statisch!
- Auch bekannt als catcall-Problem (cat = changed availablility type)
Ausweg: Laufzeitüberprüfung
```java
class Girl extends Student {
  ...
  public void setRoomMate(Student s) { //student wird aufgerufen! nicht boy oder girl, dadurch können die methoden der klasse verwendet werden
    if (s instanceof Girl)
      super.setRoomMate(s);
    else
      throw new ParentException("Oh Oh!");
  }
}
```
Nachteil: Nur zur Laufzeit überprüfung

#### Ko- und Kontravarianz für Rückgabewerte
Kovarianz (gängig):
```java
public class KlasseA {
  KlasseA ich() { return this; }
}
public class KlasseB extends KlasseA {
  KlasseB ich() { return this; }
}
```
Kontravarianz macht wenig Sinn und kommt (gängig) nicht vor

In objektorientierten Programmiersprachen im Allgemeinen
- Kontravarianz: für Eingabeparameter
- Kovarianz: für Rückgabewerte und Ausnahmen
- Invarianz: für Ein- und Ausgabeparameter

### Liskovsches Substitutionsprinzip (LSP)
Barbara Liskov, 1988 bzw. 1993, definiert stärkere Form der Subtyp-Relation, berücksichtigt Verhalten:
> Wenn es für jedes Objekt $o_1$ eines Typs S ein Objekt $o_2$ des Typs T gibt, so dass für alle Programme P, die mit Operationen von T definiert sind, das Verhalten von P unverändert bleibt, wenn $o_2$ durch $o_1$ ersetzt wird, dann ist S ein Subtyp von T.'
Subtyp darf Funktionalität eines Basistyps nur erweitern, aber nicht einschränken. <br>
Beispiel: Kreis-Ellipse $\rightarrow$ Kreis als Unterklasse schränkt Funktionalität ein und verletzt damit LSP

### Generics in Java (Typsicherheit)
Motivation: Parametrisierung von Kollektionen mit Typen
```java
LinkedList<String> liste = new LinkedList<String>();
liste.add("Generics");
String s = liste.get(0);
```
auch für Iteratoren nutzbar
```java
Iterator<String> iter = liste.iterator();
  while(iter.hasNext()) {
    String s = iter.next();
    ...
}
```
oder mit erweiterter for-Schleife
```java
for(String s : liste) {
  System.out.println(s);
}
```

Deklaration: Definition mit Typparameter
```java
class GMethod {
  static <T> T thisOrThat(T first, T second) {
    return Math.random() > 0.5 ? first : second;
  }
}
```
- T = Typparameter (oder auch Typvariable) wird wie Typ verwendet, stellt jedoch nur einen Platzhalter dar
- wird bei Instanziierung (Parametrisierung) durch konkreten Typ „ersetzt“
- nur Referenzdatentypen (Klassennamen), keine primitiven Datentypen
Anwendung:
- explizite Angabe des Typparameters
  ```java
  String s = GMethod.<String>thisOrThat("Java", "C++");
  Integer>thisOrThat(new Integer(42), new Integer(23));
  ```
- automatische Typinferenz durch Compiler
  ```java
  String s = GMethod.thisOrThat("Java", "C++");
  Integer i = GMethod.thisOrThat(new Integer(42), new Integer(23));
  ```

#### Eingrenzung von Typparametern
Festlegung einer Mindestfunktionalität der einzusetzenden Klasse, z.B. durch Angabe einer Basisklasse
- Instanziierung von T muss von Comparable abgeleitet werden (hier ein Interface, dass wiederum generisch ist, daher Comparable<T>)
- Verletzung wird vom Compiler erkannt
```java
static<T extends Comparable<T>> T min(T first, T second) {
  return first.compareTo(second) < 0 ? first : second;
}
```
Angabe des Typparameters bei der Klassendefinition:
```java
class GArray<T> {
  T[] data;
  int size = 0;
  public GArray(int capacity) { ... }
  public T get(int idx) { return data[idx]; }
  public void add(T obj) { ... }
}
```
Achtung: new T[n] ist unzulässig! Grund liegt in der Implementierung von Generics:
Es gibt zwei Möglichkeiten der internen Umsetzung generischen Codes:
- Code-Spezialisierung: jede neue Instanziierung generiert neuen Code
  - Array<String> → ArrayString, Array<Integer> → ArrayInteger
  - Problem: Codegröße
- Code-Sharing: gemeinsamer Code für alle Instanziierungen
  - Array<String> → Array<Object>, Array<Integer> → Array<Object>
  - Probleme: keine Unterstützung primitiver Datentypen & keine Anpassung von Algorithmen an Typ
Java: Code-Sharing durch Typlöschung (Type Erasure)
Typen beim Übersetzen geprüft, aber keinen Einfluss auf Code
sichert auch Kompatibilität zu nicht generischem Code (Java-Version < 1.5) Bsp.: ArrayList vs. ArrayList<E>

Beispiel: Reflektion (Metaklassen) zur Erzeugung nutzen; danach Konstruktionsaufruf
```java
public GArray(Class<T> clazz, int capacity) {
  data = (T[]) Array.newInstance(clazz, capacity);
}

GArray<String> array = new GArray<String>(String.class, 10);
```

#### Kovarianz generischer Typen
einfache Felder in Java sind kovariant
```java
Object[] feld = new Object[10];
feld[0] = "String";
feld[1] = new Integer(42);
```
Instanziierungen mit unterschiedliche Typen sind jedoch inkompatibel
```java
GArray<String> anArray = new GArray<String>();
GArray<Object> anotherArray = (GArray<Object>) anArray;
```

#### Wildcards
Wildcard „?“ als Typparameter und abstrakter Supertyp für alle Instanziierungen
```java
GArray<?> aRef;
aRef = new GArray<String>();
aRef = new GArray<Integer>();
```
aber nicht:
```java
GArray<?> aRef = new GArray<?>();
```
hilfreich insbesondere für generische Methoden
```java
// dieser Methode ist der genaue Typ egal
static void pO(GArray<?> ia) {
  for(Object o : ia) {
    System.out.print(o);
  }
}
// floats wollen wir mit Genauigkeit 2 haben
static void pF(GArray<Float> ia) {
  for(Float f : ia) {
    System.out.printf("%5.2f\n", f);
  }
}
```

Beschränkte Wildcards 
- nach „unten“ in der Klassenhierarchie $\rightarrow$ Kovarianz
  ```java 
  ? extends Supertyp 
  ```
  Anwendungsbeispiel: Sortieren eines generischen Feldes erfordert Unterstützung der Comparable-Schnittstelle
  ```java
  void sortArray(GArray<? extends Comparable> array) {
    ...
  }
  ```
- nach „oben“ in der Klassenhierarchie $\rightarrow$ Kontravarianz
  ```java
  ? super Subtyp
  ```
  Anwendungsbeispiel: Feld mit ganzen Zahlen und Objekten
  ```java
  GArray<? super Integer> array;
  // Zuweisungskompatibel zu ...
  array = new GArray<Number>();
  array = new GArray<Object>();
  array = new GArray<Integer>();
  // aber nur erlaubt:
  Object obj = array.get(0);
  ```

PECS = Producer extends, Consumer super $\rightarrow$ Producer liest nur sachen, Consumer legt daten/Objekte/... ab

# Objectorientierung am Beispiel C++
- Ziel von C++: volle Kontrolle über Speicher & Ausführungsreihenfolgen sowie skalierbarere Projekt-Größe
- Kompiliert zu nativem Maschinencode und erlaubt genauere Aussagen über Speicher-, Cache- und Echtzeitverhalten
- Viele Hochsprachenelemente (Wie Java objektorientiert; sogar ähnliche Syntax an viele Stellen (weil Java ursprünglich an C++ angelehnt))
- Jedoch kompromissloser Fokus Ausführungsgeschwindigkeit, d.h.
  - Keine automatische Speicherverwaltung
  - Keine Initialisierung von Variablen (im Allgemeinen)
  - Kein Speicherschutz!
  - Dinge, die Zeit kosten, müssen im Allgemeinen erst durch Schlüsselworte aktiviert werden
- C++ ist zu sehr großen Teilen eine Obermenge von C
  - Fügt Objektorientierung hinzu
  - Versucht fehleranfällige Konstrukte zu kapseln
  - Führt (viele) weitere Sprachkonstrukte ein, die Code kompakter werden lassen

## Vergleich mit Java
```java
[Hello.java] 
package hello; // say that we are part of a package
public class Hello { // declare a class called Hello:
// declare the function main that takes an array of Strings:
  public static void main(String args[]) {
  // call the static method, println on class System.out with parameter "Hi Welt!":
    System.out.println("Hi Welt!");
  }
} // end of class Hello
```
```cpp
[Hello.cpp]
// include declarations for I/O library where cout object is specified in namespace std::
#include <iostream>
// declare the function main that takes an int and array of strings and returns an int as the exit code
int main(int argc, char* argv[]) {
// stream string to cout object flush line with endl
  std::cout << "Hello world!"
  << std::endl;
  return 0;
} // end of main()
```
- Unterschiede im Aufbau:
  - C++ hat globale Funktionen, also außerhalb von Klassen, wie main
  - #include gibt Dateien mit Klassen- und Funktionsdefinitionen an, die der Compiler einlesen soll
  - Java-Programme werden in packages gegliedert, in C++ gibt es mit modules ein ähnliches Konzept, welches aber (noch) nicht verbreitet ist
  - C++-Programme können (ohne Bezug zu Dateien) in namespaces untergliedert werden, hier std
- Programmargumente:
  - In Java bekommt main ein String-Array übergeben, die Länge kann über .length abgefragt werden
  - C/C++-Programme erhalten ein Array von char* (Details zu Pointern folgen)
  - In C/C++ sind Arrays keine Pseudoobjekte, sondern Speicherbereiche in denen die Daten konsekutiv abgelegt sind $\rightarrow$ argc wird benötigt die Anzahl an Elementen zu kodieren
- Rückgabewerte:
  - In Java keine Rückgabe in der main-Methode
  - In C++ Rückgabe eines exit code
    - 0 gibt an: Programmausführung erfolgreich
    - Andere Werte geben einen Programm-spezifischen Fehlercode zurück
- Primitive Datentypen:
  - Wie in Java einfache Datentypen, die „Zahlen“ enthalten
  - char, short, int, long sind auf 64-bit Maschinen 8 bit, 16 bit, 32 bit und 64 bit breit (char braucht in Java 16 Bit!)
  - long ist auf 32 bit Maschinen 32 Bit breit, long long [sic!] ist immer 64 Bit
  - bool speichert Boolsche Werte (Breite hängt vom Compiler ab!)
  - Ein unsigned vor Ganzahltypen gibt an, dass keine negativen Zahlen in der Variable gespeichert werden (Beispiel: unsigned int) $\rightarrow$ Kann größere Zahlen speichern & zu viel Unsinn führen (beim Vergleich mit vorzeichenbehafteten Zahlen)

## C++ Klassen
Header Foo.hpp deklariert Struktur und Schnittstelle
```cpp
public:     // Block ohne Zugriffsbeschränkung
  Foo();    // Konstruktor
  ~Foo();   // Destruktor
protected:  // Block von Dingen, auf die auch abgeleitete Klassen zugreifen dürfen
  int num;  // Member-Variable
};          // WICHTIGES Semikolon!
```

Implementierung in getrennter Datei Foo.cpp
```cpp
#include "Foo.hpp"  // Klassen Deklaration einbinden
#include <iostream> // Einbinden von Funktionen der stdlib
Foo::Foo() :        // Implementierung des Konstuktors von Foo
  num(5) {          // Statische Initialisierung von num, Code in Klammern {} kann auch initialisieren
  std::cout << "c" << std::endl;
}
Foo::~Foo() {
  std::cout << "d" << std::endl;
}
```

- Reine Implementierung auch im Header möglich, aber Trennung von Implementierung und Deklaration erlaubt schnelleres Kompilieren
- Trennung nicht immer möglich (später mehr Details), aber im Allgemeinen zu bevorzugen
- Der scope-Operator :: wird zum Zugriff auf namespaces und zur Beschreibung der Klassenzugehörigkeit von Methoden verwendet
- Initialisierung von Variablen vor Funktionsrumpf etwas „merkwürdig“ zu lesen, aber erlaubt schnelle Implementierungen...
  - Syntax: nach Konstruktor : dann jeweils Variable(Wert)
  - Variablen durch , getrennt
  - Wichtig: Reihenfolge der Variablen wie in Deklaration der Klasse!
- Schlüsselworte private, protected und public vergleichbar zu Java, werden aber vor ganze Blöcke geschrieben
  - Kapselung nur auf Ebene von Klassen ➞ Klassen sind immer public
  - protected erlaubt nur der Klasse selber und Unterklassen den Zugriff
- Zugriffe außerhalb der Klassenstruktur können durch friend- Deklaration erlaubt werden (teilweise verrufen!)
- Auch *final* ähnlich zu Java $\righarrow$ Verhindert weiteres Ableiten von Klassen
- Schlüsselwort const markiert Methoden, die Objekte nicht verändern $\rightarrow$ Erlauben die Übergabe von Nur-Lesen-Referenzen
- Größere Unterschiede zu Java:
  - Klassen können Destruktoren besitzen
    - Werden aufgerufen wenn Objekt zerstört wird
    - Kann bspw. dafür verwendet werden, um von dem Objekt allozierte Speicherbereiche freizugeben (Achtung: anschließend darf auf diese nicht mehr zugegriffen werden – problematisch wenn anderen Objekte diese Speicherbereiche bekannt gegeben wurden!)
    - Destruktor kann Zerstören eines Objekts aber nicht verhindern
    - Methodensignatur ~Klassenname() – kein Rückgabetyp!
    - Warum gibt es das nicht in Java?
  - Neben dem Standardkonstruktor oder einem expliziten Konstruktor existiert ein Copy-Constructor
    - Methodensignatur Klassenname(const Klassenname& c)
    - Wird aufgerufen wenn Objekt kopiert werden soll
    - Vergleichbar zu Object.clone() in Java
- Überladen von Methoden vergleichbar zu Java
  - Parametertypen (oder const-Markierung) müssen sich unterscheiden!
  - Nur Veränderung des Rückgabewertes nicht ausreichend
    ```cpp
    class Foo {
      public:
        void doMagic(int i);
        void doMagic(std::string s);
    };
    ```

## C++ Präprozessor
C/C++-Code kann vor dem Übersetzen durch einen Präprozessor verändert werden
- Alle Präprozessor-Makros beginnen mit #
- (Haupt-)gründe:
  - Importieren anderer Dateien
  - An- und Ausschalten von Features je nach Compile-Optionen
  - Kapselung von Plattform-spezifischem Code
  - Vermeiden von Redundanzen
- Makros sollten vermieden werden
  - Schwierig zu lesen
  - Keine Namespaces
  - Keine Typsicherheit
- Manchmal jedoch einzige Möglichkeit

Beispiele: 
```cpp
#include "X.hpp" // Datei X.hpp aus Projekt-Ordner
#include <cstdio> // Datei cstdio aus System-Includes

#ifdef DEBUG // falls Konstante DEBUG definiert ist
std::cout << "Wichtige Debugausgabe" << std::endl;
#endif

#define DEBUG // Konstante setzen
#define VERSION 3.1415 // Konstante auf einen Wert setzen
#define DPRINT(X) std::cout << X << std::endl; // Macro-Fkt.
#undef DEBUG // Konstante löschen, good practice!

#ifndef __linux__ // falls nicht für Linux übersetzt
playMinesweeper();
#endif
```

### Einschub: Include Guards
Eine (oft hässliche) Eigenschaft des #include-Befehls: kein Überprüfen ob eine Datei vorher bereits eingebunden wurde. Problematisches Beispiel:
```cpp
#include "Bar.hpp" //in "Bar.hpp" ist "Foo.hpp" bereits inkludiert worden
#include "Foo.hpp" //Fehler weil kallse Foo bereits deklariert wurde
```
Common Practice: Include-Guards um alle Header-Dateien
```cpp
#ifndef FOO_HPP
#define FOO_HPP
...
#endif
```

## Speichermanagement
- Programmspeicher enthält Code und Daten, vom Betriebssystem i.A. auf virtuelle Adressbereiche abgebildet
- Unterschiedliche Varianten von Datenspeicher:
  - Stack hält alle Variablen einer Methode, aller aufrufenden Methoden, Parameter, Rückgabewerte und einige Management-Daten
  - Heap hält Variablen und Objekte, die nicht direkt über Methodenaufrufe übergeben werden
  - Speicher für globale und statische Objekte und Variablen
- Java legt primitive Datentypen im Stack ab und Objekte im Heap
- C++ kann sowohl primitive Datentypen als auch Objekte in Stack und Heap abbilden
- Für den Stack bieten Java und C++ automatisches Speicher-Mgmt.
- Für den Heap bietet nur Java automatisches Speicher-Mgmt.

### Eigenschaften des Stack-Speichers:
  - Variablen/Objekte haben klare Lebensdauer $\rightarrow$ Werden immer gelöscht wenn Funktion verlassen wird  $\rightarrow$ Man kann Speicher nicht „aufheben“
  - In der Regel sehr schnell, weil im Prozessor-Cache
  - In der Größe begrenzt, z.B. 8MB bei aktuellen Linux-Systemen
  - Für flexiblere Speicherung brauchen wir anders organisierten Speicher...
  
### Heap: Keine klare Struktur
  - Anlegen: in C++ & Java mit new
  - Um angelegten Speicher anzusprechen: Zeiger und Referenzen
    - In Java automatisch Zeiger
    - In C++ Zeiger durch * hinter Typ
    ```cpp
    int main() {
      int* i = new int[3];
      int* j = new int;
      delete [] i;
      delete j;
      return 0;
    }
    ```
  - Löschen von Heap-Speicher: 
    - Java automatisch
    - In C++ nur manuell
      - durch genau einen Aufruf von delete
      - Programmierer ist dafür verantwortlich, dass danach kein Zeiger auf diesen Speicher mehr benutzt wird
  - Warum der Unterschied?
    - Nicht einfach festzustellen, wann letzter Zeiger auf Objekt gelöscht wurde
      - Zeiger können selbst auch im Heap gespeichert sein
      - Zyklische Referenzen!
    - Relativ aufwändiges Scannen, in Java durch regelmäßige Garbage Collection gelöst
      - Führt zu Jitter (Schwankung der Zeitdauer, die bestimmte Programmabschnitte zur Bearbeitung benötigen) & Speicher-Overhead, ...

Beispiele
  - Anlegen eines Objects auf dem Heap:
    ```cpp
    std::string* s = new std::string("wiz!");
    delete s;
    ```
  - Allokation von Feldern:
    ```cpp
    int* i = new int[29]; // gültige Indicies 0-28
    i[0] = 23;
    delete [] i; // nicht mit delete i; verwechseln!
    ```
  - Zeiger können durch & auf beliebige Variablen ermittelt werden
    ```cpp
    int i = 0;
    int* j = &i; // &-Operator erzeugt Zeiger; j darf nicht gelöscht werden
    ``` 
  - Zeiger können durch * dereferenziert werden
    ```cpp
    int i = 0;
    int* j = &i; // &-Operator erzeugt Zeiger
    *j = 1; // Zugriff auf Variableninhalt
    ``` 
  - Zugriff auf Methoden/Member Variablen
    ```cpp
    std::string* s = new std::string("wiz");
    (*s).push_back('?'); // manuelles Derefenzieren
    s->push_back('?'); // -> Operator
    delete s;
    ``` 
  - C++ übergibt alles als Kopie
    ```cpp
    void set(std::string s) { s = "foo"; }
    int main() {
    std::string s = "bar";
    set(s);
    std::cout << s; // gibt bar aus
    return 0;
    }
    ```
  - Zeiger können verwendet werden, um schreibend zuzugreifen
    ```cpp
    void set(std::string* s) { *s = "foo"; }
    int main() {
    std::string s = "bar";
    set(&s);
    std::cout << s; // gibt foo aus
    return 0;
    }
    ```
  - Zeiger erlauben syntaktisch sehr viele Dinge mit unvorhersehbaren Nebenwirkungen
    ```cpp
    std::string* magicStr() {
    std::string s("wiz!");
    return &s; // gibt Speicher auf Stack weiter; Tun Sie das nie!
    }
    int main() {
    std::string* s = magicStr();
    std::cout << *s; // Stack ist bereits überschrieben!
    return 0;
    }
    ```

Warum wirken sich Speicherfehler so unvorhersehbar aus?
- Speicherfehler entstehen sehr häufig durch Zugriff auf Speicherbereiche nachdem diese freigegeben worden sind
- Ob hierdurch später ein Fehler auftritt, hängt davon ab wie der freigegebene Speicher nach der Freigabe wieder genutzt wird
- Die insgesamte Speichernutzung wird durch die Gesamtheit aller Speicherallokationen und -freigaben beeinflusst
- Das kann dazu führen, dass ein Speicherfehler in Modul X erst lange nach seinem Entstehen Auswirkungen zeigt, nachdem in einem anderen Modul Y eine Änderung eingeführt wurde
- Auch eingebundene dynamische Bibliotheken haben Einfluss
- Das macht es so schwierig, solche Fehler schwierig zu finden

### Bessere Alternative: Referenzen
- Zeigen ebenfalls auf Speicher, Compiler stellt aber sicher, dass Speicher gültig ist (wenn man nicht in Zeiger wandelt etc.)!
- Markiert durch Suffix &
- Beispiel:
  ```cpp
  void set(std::string& s) { s = "foo"; }
    int main() {
    std::string s = "bar";
    set(s);
    std::cout << s; // gibt foo aus
    return 0;
  }
  ```
- Dereferenzierung durch * und -> nicht notwendig
- Referenzen sind toll, haben aber eine Einschränkung:
  ```cpp
    std::string& magicStr() {
    std::string s("wiz!");
    return s; //< FEHLER
    }
  ```
  ```cpp
    std::string& magicStr() {
    static std::string s("wiz!");
    return s; // klappt prima
    }
  ```
- Per Referenz übergebene Rückgabewerte müssen im Speicher noch existieren, wenn Methodenaufruf abgeschlossen ist...
  - OK für globale Variablen, Member-Variablen, statische Variablen...
  - Nicht-OK für Speicher der wirklich dynamisch alloziert werden muss
- Allgemein bleiben nur Zeiger und Heap:
  ```cpp
  std::string* magicStr() {
    std::string* s = new std::string("wiz!");
    return s; // klappt prima, aber: aufpassen wann s gelöscht
    // werden kann und vollständig vergessen wurde!
  }
  ```

- Konvertierung von Zeigern zu Referenzen mit „*“-Operator:
  ```cpp
    std::string& s = *magicStr(); // Konvertieren in Referenz; Delete nicht mehr möglich
    std::string s2 = *magicStr(); // Konvertieren in Referenz & Kopie! Delete nicht direkt möglich
  ```
- Konvertierung von Referenzen zu Zeigern mit „&“-Operator:
  ```cpp
    std::string s("bla");
    std::string* sStar = &s; // Konvertieren in Zeiger
  ```

- Abschließende Bemerkungen zum Speicher
  - Niemals Speicher doppelt löschen – Niemals Löschen vergessen!
  - Häufige Praxis: Zeiger auf NULL setzen nach dem Löschen (Aber: gibt es danach wirklich keinen anderen Zeiger mehr?)
  - Nur Speicher löschen, der mit „new“ allokiert wurde
  - Speicher der mit „new“ allokiert wurde in jedem möglichen Programmablauf löschen (selbst wenn Exceptions auftreten)...
  - Nie über Feldgrenzen hinweg lesen/schreiben (auch negative Indizes!)
  - Programme ausgiebig testen (dabei Address Sanitizer aktivieren!)
  - Statische Code Analyse nutzen: z.B. http://cppcheck.sourceforge.net
  - malloc/free sind Äquivalente in Sprache C und nicht typsicher!

- Verbreitetes Vorgehen in C++ (Pattern): Resource Acquisition Is Initialization (RAII)
  - Speicher (oder Ressourcen im Allgemeinen) wird nur im Konstruktor einer Klasse reserviert
  - Destruktor gibt Speicher frei
  - Sicheres (Exceptions!), nachvollziehbares Konstrukt
  - Beispiel: (Funktioniert leider noch nicht immer)
    ```cpp
      class MagicString {
      std::string* s;
      public:
      MagicString() : s(new std::string("wiz!")) {}
      std::string* magicStr() { return s; }
      ~MagicString() { delete s; }
      };
    ```

## Vererbung
- Vermeiden von Mehrfachimplementierungen
- Vermeiden von Dopplung interner Daten
- Vererbung syntaktisch ebenfalls ähnlich zu Java:
  ```java
  class Foo {
    public:
      int magic() const { return 23; }
      int enchanting() const { return 0xbeef; }
  };
  class FooBar : public Foo {
    public:
      int magic() const { return 42; }
  };
  ```
- Unterschied zu Java: Methoden „liegen“ bei C++ statisch im Speicher
  - D.h. f.magic(); ruft statisch magic-Methode in Klasse Foo auf, weil f eine Referenz vom Typ Foo ist
  - Vermeidet Mehrfachimplementierungen, realisiert aber keine einheitliche Schnittstelle!
- Nach Überschreiben einer Methode wollen wir meist, dass genutzte Methode nicht vom Referenztyp abhängt, sondern vom Objekttyp
  - Idee zu jedem Objekt speichern wir Zeiger auf zu nutzende Methoden
  - Tabelle wird *vtable* bezeichnet
  - Markierung von Methoden, für die ein Zeiger vorgehalten wird, mit Schlüsselwort virtual
  - Funktionierendes Beispiel:
    ```cpp
    class Foo {
      public:
        virtual int magic() const { return 23; }
    };
    class FooBar : public Foo {
      public:
        int magic() const override { return 42; }
    };
    int r(const Foo& f) { return f.magic(); }
    int main() {
      return r(FooBar()); // yeah gibt 42 zurück!
    }
    ```
    - virtual-Markierung genügt in Oberklasse, alle abgeleiteten Methoden ebenfalls „virtuell“
    - override-Markierung optional, aber hätte vor fehlendem virtual gewarnt!

## Mehrfachvererbung
- C++ unterstützt keine Interfaces
- Aber C++ unterstützt Mehrfachvererbung! Pro Interface eine Basisklasse -> mit abstrakten Methoden erstellen
- Gute Praxis: Explizites Überschreiben
  ```cpp
  class NiceFooBar : public Foo, public Bar {
    // erlaube NiceFooBar().magic()
    int magic() const override { return Bar::magic(); }
  };
  ```
  - Wegen Mehrfachvererbung: kein super::
  - Stattdessen immer NameDerBasisKlasse::
- Aber: Diamond Problem
  - Markieren der Ableitung als virtual behebt das Problem

Komposition statt Vererbung
- Vererbungshierarchien werden trotzdem häufig als zu unflexibel angesehen
- Ein möglicher Ausweg:
  - Klassen flexiblen aus anderen Objekten zusammensetzen
  - Einzelobjekte modellieren Aspekte des Verhaltens des Gesamtobjekts
  - Werden beim Anlegen des Gesamtobjekts übergeben
- Engl.: Prefer composition over inheritance
```cpp
class Automatisierungsmodul {
  public:
    void steuere() = 0;
};
class Roboter : public Automatisierungsmodul{
  public:
    void steuere() { /* call HAL */ }
};
class DumbDevice : public Automatisierungsmodul {
  public:
    void steuere() { /* do nothing */ }
};
class Geraet {
  protected:
    Automatisierungsmodul* _a;
    Geraet(Automatisierungsmodul* a, Saeuberungsmodul* s): _a(a), _s(s) {}
  public:
    void steuere() { _a->steuere(); }
};
```

## Operator Overloading
- In Java: Unterschied zwischen "==" und "equals()" bei String-Vergleich
- In C++: "=="-Operator für String-Vergleich
- Umsetzung: Hinzufügen einer Methode mit Namen *operatorx* wobei für x unter anderem zulässig: $+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= <=> && || ++ -- , ->* -> () []$
- Vereinfacht Nutzung komplexer Datentypen teilweise sehr stark
- Aber: Erfordert Disziplin beim Schreiben von Code
  - Oft erwartet: Freiheit von Exceptions (Wer gibt Speicher frei, wenn eine Zuweisung fehlgeschlagen ist?)
  - Semantik der Operatoren muss selbsterklärend sein
    - Ist der Operator auf einem multiplikativen Ring + oder * ?
    - Was ist, wenn zwei ungleiche Objekte jeweils kleiner als das andere sind?
    - Ist * bei Vektoren das Skalar- oder das Kreuzprodukt (oder etwas ganz anderes)?

## Templates
- Generische Datentypen werden in C++ mit Templates realsiert
- Häufig ähnlich eingesetzt wie Generics, aber können neben Typen auch Konstanten enthalten
- Zur Compile-Zeit aufgelöst ➞ Deklaration & Implementierung in Header-Dateien
- Einfaches Beispiel (mit Typen, ähnl. zu Generics, primitive Typen ok!):
  ```cpp
    template<typename T> // typename keyword -> deklariert T als Typ
    T max(T a, T b) {
      return (a > b ? a : b);
    }
  ```
  ```cpp
  int i = 10;
  int j = 2;
  int k = max<int>(j, i); // explizit
  int l = max(j, i); // automat. Typinferenz durch Parametertypen
  ```
- Ein wichtiges Grundkonzept von Templates: Substitution failure is not an error (SFINAE) es -> wird solange nach passenden Templates (in lexikogr. Reihenfolge) gesucht bis Parameter passen (sonst Fehler!)
- Sehr häufig verwendetes Konstrukt & mächtiger als es scheint, aber schwer zu beherrschen
  - Wir können alternativ versuchen, durch SFINAE zu verhindern, dass Funktionen doppelt definiert sind
  - Trick: Einführen eines Pseudoparameters, der nicht benutzt wird
    ```cpp
    template<typename T>
    T quadrieren(T i, typename T::Val pseudoParam = 0) {
      T b(i); b *= i; return b;
    }
    ```
  - Trick: Einführen eines Hilfstemplates (sogenannter trait): wenn arithmetic<T>::Cond definiert ist, muss T = int sein
    ```cpp
    template<typename T> struct arithmetic {};
    template<> struct arithmetic<int> { using Cond = void*; };
    ```
  - Definition einer Funktion, die nur für int instanziiert werden kann:
    ```cpp
    template<typename T>
    T quadrieren(T i, typename arithmetic<T>::Cond = nullptr) {
      return i * i;
    }
    ```

## Container
- Templates werden an vielen Stellen der C++ Standard-Bibliothek verwendet
- Container implementieren alle gängigen Datenstrukturen
- Prominente Beispiele:
  ```cpp
  template<typename T> class vector; // dynamisches Array
  template<typename T> class list; // doppelt verkette Liste
  template<typename T> class set; // geordnete Menge basiert auf Baum
  template<typename K, typename V> class map; // Assoziatives Array, geordnet
  // wie oben aber basierend auf Hash-Datenstruktur
  template<typename T> class unordered_set;
  template<typename K, typename V> class unordered_map;
  ```
  - Alle Templates sind stark vereinfacht dargestellt, weitere Parameter haben Standardwerte, die z.B. Speicherverhalten regeln

### Container Enumerieren
- Je nach Struktur unterschiedlicher Zugriff
- Oft über Iteratoren vom Typ Container::iterator, bspw. vector<int>::iterator
    ```cpp
    std::vector<int> v{ 1, 2, 3 }; // Initialisierung über Liste
    // “normale” for-Schleife, Beachte: Überladene Operatoren ++ und *
    for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
      std::cout << *i << std::endl;
    }
    // auto erlaubt Typinferenz → Code lesbarer, aber fehleranfälliger
    for(auto i = v.begin(); i != v.end(); ++i) {
      std::cout << *i << std::endl;
    }
    // range loop (nutzt intern Iteratoren), komplexe Datentypen nur mit Ref. “&” sonst werden Kopie erzeugt!
    for(int i : v) { // hier ohne “&”, da nur int in v gespeichert
      std::cout << i << std::endl;
    }
    ```

### Container Einfügen
- Unterschiedliche Operationen je nach Container-Typ
- std::vector<T>::push_back() fügt neues Element am Ende ein
  - Allokiert ggf. neuen Speicher
  - Exisitierende Pointer können dadurch invalidiert werden!!!
- std::list<T> zusätzlich push_front() fügt Element am Anfang ein
- std::set, std::map, …
  - insert() fügt Element ein, falls es nicht existiert (Optional mit Hinweis wo ungefähr eingefügt werden soll)
  - operator[] erlaubt Zugriff aber auch Überschreiben alter Elemente
  - emplace() Einfügen, ohne Kopien zu erzeugen (nicht behandelt)

### Container Löschen
- Unterschiedliche Operationen je nach Container-Typ
- Allgemein: erase(Container::iterator) (Vorsicht ggf. werden Iterator/Zeiger auf Objekte dadurch ungültig!)
- std::vector<T>::resize() löscht implizit letzte Elemente bei Verkleinerung
- std::vector<T>::pop_back()entfernt letztes Element
- std::list<T> hat zusätzlich pop_front()
- std::set, std::map, … löschen nur mit erase()


## Shared Pointer
- Synonym: Smart Pointer
- Ziel: Sichereres Verwenden von Speicher
- Idee: kleine, schlanke Zeiger-Objekte, die Referenzzähler + Zeiger auf komplexere Objekte enthalten, wird letztes Zeiger-Objekt gelöscht, wird auch das komplexe Objekt gelöscht
- Realisierung mit RAII, Templates, Operator-Überladung
- Beispiel, wie shared_ptr sich verhalten sollten
  ```cpp
  using stringP = shared_ptr<std::string>;
  stringP hello() { // gibt kopie der referenz zurück
    return stringP(new std::string("Hello!"));
  }

  int main() {
    stringP x = hello();
    stringP y(x); // Erstellen einer weiteren Referenz
    std::cout << y->length();
    return 0; // Original-String wird gelöscht wenn letzte Ref. weg
  }

  template<class T> class shared_ptr { // Vereinfacht!
    T* p; // Zeiger auf eigentliches Objekt
    int* r; // Referenzzähler
  public:
    // neue Referenz auf Objekt erzeugen
    shared_ptr(T* t) : p(t), r(new int) { *r = 1; }
    // Referenz durch andere Referenz erzeugen
    shared_ptr(const shared_ptr<T>& sp) : p(sp.p), r(sp.r) { ++(*r); }
    T* operator->() const { // benutzen wie einen richtigen Zeiger
      return p;
    }
    ~shared_ptr() {
      if(--(*r) == 0) { // Objekt loeschen, wenn letzte Referenz weg
        delete r;
        delete p;
      }
    }
  }; // TODO operator= implementieren!
  ```

# Einführung in Funktionale Programmierung
## Applikaive Algorithmen
Grundidee:
- Definition zusammengesetzter Funktionen durch Terme: $f(x) = 5x + 1$
- Unbestimmte:
  - x, y, z, . . . vom Typ int
  - q, p, r , . . . vom Typ bool
- Terme mit Unbestimmten (z.B. Terme vom Typ int: $x, x - 2, 2x + 1, (x + 1)(y - 1)$)
- Terme vom Typ bool $p, p Λ true, (p V true) ⇒ (q V false)$

> Sind $v_1, ..., v_n$ Unbestimmte vom Typ $\tau_1,...,\tau_n$ (bool oder int) und ist $t(v_1, ..., v_n)$ ein Term, so heißt $f(v_1, ..., v_n) = t(v_1, ..., v_n)$ eine Funktionsdefinition vom Typ $\tau$ . $\tau$ ist dabei der Typ des Terms.

- Erweiterung der Definition von Termen
- Neu: Aufrufe definierter Funktionen sind Terme

> Ein applikativer Algorithmus ist eine Menge von Funktionsdefinitionen. Die erste Funktion $f_1$ wird wie beschrieben ausgewertet und ist die Bedeutung (Semantik) des Algorithmus.

- Kategorisierung nach unterschiedlichen Kriterien
- Ordnung der Sprache
  - Erster Ordnung:
    - Funktionen können (nur) definiert und aufgerufen werden
  - Höherer Ordnung:
    - Funktionen können außerdem als Parameter an Funktionen übergeben werden und/oder Ergebnisse von Funktionen sein.
    - Funktionen sind hier auch Werte! -- erstklassige Werte;
    - Erstklassig: Es gibt keine Einschränkungen.
    - Umgekehrt: Wert ist eine Funktion ohne Parameter
- Auswertungsstrategie:
  - Strikte Auswertung:
    - Synonyme: strict evaluation, eager evaluation, call by value, applikative Reduktion
    - Die Argumente einer Funktion werden vor Eintritt in die Funktion berechnet (ausgewertet) – wie z.B. in Pascal oder C.
  - Bedarfsauswertung:
    - Synonyme: Lazy evaluation, call by need
    - Funktionsargumente werden unausgewertet an die Funktion übergeben
    - Erst wenn die Funktion (in ihrem Körper) die Argumente benötigt, werden die eingesetzten Argumentausdrücke berechnet, und dann nur einmal.
    - Realisiert „Sharing“ (im Unterschied zur Normalform-Reduktion – dort werden gleiche Ausdrücke immer wieder erneut berechnet).
- Typisierung:
  - Stark typisiert: Die verbreiteten funktionalen Programmiersprachen sind stark typisiert, d.h. alle Typfehler werden erkannt.
    - Statisch typisiert: Typprüfung wird zur Übersetzungszeit ausgeführt.
    - Dynamisch typisiert: Typprüfung wird zur Laufzeit ausgeführt
  - Untypisiert: Reiner Lambda-Kalkül (später)

## Die funktionale Programmiersprache Erlang
- Entwickelt ab der zweiten Hälfte der 1980er Jahre im Ericsson Computer Science Laboratory (CSLab, Schweden)
- Ziel war, eine einfache, effiziente und nicht zu umfangreiche Sprache, die sich gut zur Programmierung robuster, großer und nebenläufiger Anwendungen für den industriellen Einsatz eignet. 
- Erste Version einer Erlang-Umgebung entstand 1987 auf der Grundlage von Prolog. Später wurden Bytecode-Übersetzer und abstrakte Maschinen geschaffen.

### Arbeiten mit Erlang
- Erlang-Programme werden durch Definition der entsprechenden Funktionen in Modulen erstellt
- Module können in den Erlang-Interpreter geladen und von diesem in Zwischencode übersetzt werden
- Anschließend können Anfragen im Interpreter gestellt werden

Modul "fakultaet.erl":
```erlang
  -module(fakultaet).
  -export([fak/1]).
  fak(0) -> 1;
  fak(N) when N > 0 -> (N) * fak(N-1).
```
Laden in Interpreter mittels: ```c(fakultaet)```
Testen der Funktion, z.B. mit: ```fakultaet:fak(5)```

### Elemente von Erlang
- Ganzzahlen (Integer):
  - 10
  - -234
  - 16#AB10F
  - 2#110111010
  - $A
  - B#Val erlaubt Zahlendarstellung mit Basis B (mit B ≤ 36).
  - $Char ermöglicht Angabe von Ascii-Zeichen ($A für 65).
- Gleitkommazahlen (Floats):
  - 17.368
  - -56.654
  - 12.34E-10.
- Atome (Atoms):
  - abcef
  - start_with_a_lower_case_letter
  - 'Blanks can be quoted'
  - 'Anything inside quotes \n\012'
  - Erläuterungen:
    - Atome sind Konstanten, die Ihren eigenen Namen als Wert haben
    - Atome beliebiger Länge sind zulässig
    - Jedes Zeichen ist innerhalb eines Atoms erlaubt
    - Einige Atome sind reservierte Schlüsselwörter und können nur in der von den Sprachentwicklern gewünschen Weise verwendet werden als Funktionsbezeichner, Operatoren, Ausdrücke etc. 
    - Reserviert sind: *after and andalso band begin bnot bor bsl bsr bxor case catch cond div end fun if let not of or orelse query receive rem try when xor*
- Tupel (Tuples):
  - {123, bcd} % Ein Tupel aus Ganzzahl und Atom
  - {123, def, abc}
  - {person, 'Joe', 'Armstrong'}
  - {abc, {def, 123}, jkl}
  - {}
  - Erläuterungen:
    - Können eine feste Anzahl von “Dingen” speichern
    - Tupel beliebiger Größe sind zulässig
    - Kommentare werden in Erlang mit % eingeleitet und erstrecken sich dann bis zum Zeilenende
- Listen:
  - [123, xyz]
  - [123, def, abc]
  - [{person, 'Joe', 'Armstrong'}, {person, 'Robert', 'Virding'}, {person, 'Mike', 'Williams'}]
  - "abcdefgh" wird zu [97,98,99,100,101,102,103,104]
  - "" wird zu []
  - Erläuterungen:
    - Listen können eine variable Anzahl von Dingen speichern
    - Die Größe von Listen wird dynamisch bestimmt
    - "..." ist eine Kurzform für die Liste der Ganzzahlen, die die ASCIICodes der Zeichen innerhalb der Anführungszeichen repräsentieren
- Variablen:
  - Abc
  - A_long_variable_name
  - AnObjectOrientatedVariableName
  - Erläuterungen:
    - Fangen grundsätzlich mit einem Großbuchstaben an 
    - Keine „Funny Characters"
    - Variablen werden zu Speicherung von Werten von Datenstrukturen verwendet
    - Variablen können nur einmal gebunden werden!
    - Der Wert einer Variablen kann also nicht mehr verändert werden, nachdem er einmal gesetzt wurde: *N = N + 1 VERBOTEN!*
    - Einzige Ausnahmen: Die anonyme Variable "_" (kein Lesen möglich) und das Löschen einer Variable im Interpreter mit f(N).
- Komplexe Datenstrukturen:
  - [{{person,'Joe', 'Armstrong'}, {telephoneNumber, [3,5,9,7]}, {shoeSize, 42}, {pets, [{cat, tubby},{cat, tiger}]}, {children,[{thomas, 5},{claire,1}]}}, {{person,'Mike','Williams'}, {shoeSize,41}, {likes,[boats, beer]}, ... }]
  - Erläuterungen:
    - Beliebig komplexe Strukturen können erzeugt werden
    - Datenstrukturen können durch einfaches Hinschreiben erzeugt werden (keine explizite Speicherbelegung oder -freigabe)
    - Datenstrukturen können gebundene Variablen enthalten
- Pattern Matching:
  - $A = 10$ erfolgreich, bindet A zu 10 
  - ${B, C, D} = {10, foo, bar}$ erfolgreich, bindet B zu 10, C zu foo and D zu bar
  - ${A, A, B} = {abc, abc, foo}$ erfolgreich, bindet A zu abc, B zu foo
  - ${A, A, B} = {abc, def, 123}$ schlägt fehl (“fails”)
  - $[A,B,C] = [1,2,3]$ erfolgreich, bindet A zu 1, B zu 2, C zu 3
  - $[A,B,C,D] = [1,2,3]$ schlägt fehl
  - $[A,B|C] = [1,2,3,4,5,6,7]$ erfolgreich bindet A zu 1, B zu 2, C zu [3,4,5,6,7]
  - $[H|T] = [1,2,3,4]$ erfolgreich, bindet H zu 1, T zu [2,3,4]
  - $[H|T] = [abc]$ erfolgreich, bindet H zu abc, T zu []
  - $[H|T] = []$ schlägt fehl
  - ${A,_, [B|_],{B}} = {abc,23,[22,x],{22}}$ erfolgreich, bindet A zu abc, B zu 22
  - Erläuterungen: 
    - „Pattern Matching“, zu Deutsch „Mustervergleich“, spielt eine zentrale Rolle bei der Auswahl der „richtigen“ Anweisungsfolge für einen konkreten Funktionsaufruf und dem Binden der Variablen für die Funktionsparameter (siehe spätere Erklärungen)
    - Beachte die Verwendung von "_", der anonymen (“don't care”) Variable (diese Variable kann beliebig oft gebunden, jedoch nie ausgelesen werden, da ihr Inhalt keine Rolle spielt).
    - Im letzten Beispiel wird die Variable B nur einmal an den Wert 22 gebunden (das klappt, da der letzte Wert genau {22} ist)
- Funktionsaufrufe:
  - module:func(Arg1, Arg2, ... Argn)
  - func(Arg1, Arg2, .. Argn)
  - Erläuterungen:
    - Arg1 .. Argn sind beliebige Erlang-Datenstrukturen
    - Die Funktion und die Modulnamen müssen Atome sein (im obigen Beispiel module und func)
    - Eine Funktion darf auch ohne Parameter (Argumente) sein (z.B. date() – gibt das aktuelle Datum zurück)
    - Funktionen werden innerhalb von Modulen definiert
    - Funktionen müssen exportiert werden, bevor sie außerhalb des Moduls, in dem sie definiert sind, verwendet werden
    - Innerhalb ihres Moduls können Funktionen ohne den vorangestellten Modulnamen aufgerufen werden (sonst nur nach einer vorherigen Import-Anweisung)
- Modul-Deklaration:
  ```erlang
    -module(demo).
    -export([double/1]).
    double(X) -> times(X, 2).
    times(X, N) -> X * N.
  ```
  - Erläuterungen:
    - Die Funktion double kann auch außerhalb des Moduls verwendet werden, times ist nur lokal in dem Modul verwendbar
    - Die Bezeichnung double/1 deklariert die Funktion double mit einem Argument 
    - Beachte: double/1 und double/2 bezeichnen zwei unterschiedliche Funktionen
- Eingebaute Funktionen (Built In Functions, BIFs)
  - date()
  - time()
  - length([1,2,3,4,5])
  - size({a,b,c})
  - atom_to_list(an_atom)
  - list_to_tuple([1,2,3,4])
  - integer_to_list(2234)
  - tuple_to_list({})
  - Erläuterungen:
    - Eingebaute Funktionen sind im Modul erlang deklariert
    - Für Aufgaben, die mit normalen Funktionen nicht oder nur sehr schwierig in Erlang realisiert werden können
    - Verändern das Verhalten des Systems
    - Beschrieben im Erlang BIFs Handbuch
- Definition von Funktionen:
  ```erlang
  func(Pattern1, Pattern2, ...) ->
    ... ; % Vor dem ; steht der Rumpf
  func(Pattern1, Pattern2, ...) ->
    ... ; % Das ; kündigt weitere Alternativen an
    ... % Beliebig viele Alternativen möglich
  func(Pattern1, Pattern2, ...) ->
    ... . % Am Ende muss ein Punkt stehen!
  ```
  - Erläuterungen:
    - Funktionen werden als Sequenz von Klauseln definiert 
    - Sequentielles Testen der Klauseln bis das erste Muster erkannt wird (Pattern Matching)
    - Das Pattern Matching bindet alle Variablen im Kopf der Klausel
    - Variablen sind lokal zu jeder Klausel (automatische Speicherverw.)
    - Der entsprechende Anweisungsrumpf wird sequentiell ausgeführt

Was passiert wenn wir mathstuff:factorial() mit einem negativen Argument aufrufen? Der Interpreter reagiert nicht mehr?
- Erste Reaktion: rette das Laufzeitsystem durch Eingabe von CTRL-G
  - User switch command
    01.  --> h
    02.  c [nn] - connect to job
    03.  i [nn] - interrupt job
    04.  k [nn] - kill job
    05.  j - list all jobs
    06.  s [shell] - start local shell
    07.  r [node [shell]] - start remote shell
    08.  q - quit erlang
    09.  ? | h - this message
    10. -->
  - Liste durch Eingabe von j alle Jobnummern auf
  - Beende den entsprechenden Shell-Job durch k <jobnr>
  - Starte eine neue Shell durch Eingabe von s
  - Liste durch erneute Eingabe von j die neuen Jobnummern auf
  - Verbinde durch Eingabe von c <shelljobnr> mit neuer Shell
- Zweite Reaktion: Ergänze factorial() um zusätzliche Bedingung:
  - „Beschütze“ die Funktion vor Endlosrekursion durch Ergänzung eines sogenannten Wächters (Guards) bei dem entsprechenden Fallmuster  (Pattern)
  - Erläuterungen:
    - Der Guard wird durch das Atom when und eine Bedingung vor dem Pfeil -> formuliert
    - Vollständig „beschützte“ Klauseln können in beliebiger Reihenfolge angeordnet werden
    - Achtung: Ohne Guard führt diese Reihenfolge zu Endlosschleifen
  - Beispiele für Guards:
    - number(X)       % X is a number
    - integer(X)      % X is an integer
    - float(X)        % X is a float
    - atom(X)         % X is an atom
    - tuple(X)        % X is a tuple
    - list(X)         % X is a list
    - length(X) == 3  % X is a list of length 3
    - size(X) == 2    % X is a tuple of size 2.
    - X > Y + Z       % X is > Y + Z
    - X == Y          % X is equal to Y
    - X =:= Y         % X is exactly equal to Y (i.e. 1 == 1.0 succeeds but 1 =:= 1.0 fails)
  - Alle Variablen in einem Wächter müssen zuvor gebunden werden

- Traversieren (“Ablaufen”) von Listen:
  ```
    average(X) -> sum(X) / len(X).
    sum([H|T]) -> H + sum(T); % summiert alle Werte auf
    sum([]) -> 0.
    len([_|T]) -> 1 + len(T); % Wert des Elements
    len([]) -> 0. % interessiert nicht
  ```
  - Die Funktionen sum und len verwenden das gleiche Rekursionsmuster
  - Zwei weitere gebräuchliche Rekursionsmuster:
    ```
    double([H|T]) -> [2*H|double(T)];   % verdoppelt alle
    double([]) -> [].                   % Listenelemente

    member(H, [H|_]) -> true;           % prüft auf
    member(H, [_|T]) -> member(H, T);   % Enthaltensein
    member(_, []) -> false.             % in Liste
    ```
- Listen und Akkumulatoren:
  ```
    average(X) -> average(X, 0, 0).
    average([H|T], Length, Sum) -> average(T, Length + 1, Sum + H);
    average([], Length, Sum) -> Sum / Length.
  ```
  - Interessant sind an diesem Beispiel:
    - Die Liste wird nur einmal traversiert 
    - Der Speicheraufwand bei der Ausführung ist konstant, da die Funktion “endrekursiv” ist (nach Rekursion steht Ergebnis fest)
    - Die Variablen Length und Sum spielen die Rolle von Akkumulatoren
    - Bemerkung: average([]) ist nicht definiert, da man nicht den Durchschnitt von 0 Werten berechnen kann (führt zu Laufzeitfehler)
- „Identisch“ benannte Funktionen mit unterschiedlicher Parameterzahl:
  ```
  sum(L) -> sum(L, 0).
  sum([], N) -> N;
  sum([H|T], N) -> sum(T, H+N).
  ```
  - Erläuterungen:
    - Die Funktion sum/1 summiert die Elemente einer als Parameter übergebenen Liste
    - Sie verwendet eine Hilfsfunktion, die mit sum/2 benannt ist
    - Die Hilfsfunktion hätte auch irgendeinen anderen Namen haben können
    - Für Erlang sind sum/1 und sum/2 tatsächlich unterschiedliche Funktionsnamen
- Shell-Kommandos:
  - h() - history . Print the last 20 commands.
  - b() - bindings. See all variable bindings.
  - f() - forget. Forget all variable bindings.
  - f(Var) - forget. Forget the binding of variable X. This can ONLY be used as a command to the shell - NOT in the body of a function!
  - e(n) - evaluate. Evaluate the n:th command in history. 
  - e(-1) Evaluate the previous command.
  - Erläuterungen: Die Kommandozeile kann wie mit dem Editor Emacs editiert werden (werl.exe unterstützt zusätzlich Historie mit Cursortasten)
- Spezielle Funktionen: 
  ``` 
  apply(Func, Args)
  apply(Mod, Func, Args) % old style, deprecated
  ```
  - Erläuterungen:
    - Wendet die Funktion Func (im Modul Mod bei der zweiten Variante) auf die Argumente an, die in der Liste Args enthalten sind
    - Mod und Func müssen Atome sein bzw. Ausdrücke, die zu Atomen evaluiert werden und die eine Funktion bzw. Modul referenzieren 
    - Jeder Erlang-Ausdruck kann für die Formulierung der an die Funktion zu übergebenden Argumente verwendet werden
    - Die Stelligkeit der Funktion ist gleich der Länge der Argumentliste 
    - Beispiel: ```` 1> apply( lists1,min_max,[[4,1,7,3,9,10]]).``` ->  {1, 10}
      - Bemerkung: Die Funktion min_max erhält hier ein (!) Argument
- Anonyme Funktionen:
  ```
  Double = fun(X) -> 2*X end.
  > Double(4).
  > 8
  ```
  - Erläuterung: 
    - Mittels “fun” können anonyme Funktionen deklariert werden
    - Diese können auch einer Variablen (im obigen Beispiel Double) zugewiesen werden
    - Interessant wird diese Art der Funktionsdefinition, da anonyme Funktionen auch als Parameter übergeben bzw. als Ergebniswert zurückgegeben werden können
    - Die Funktionen, die anonyme Funktionen als Parameter akzeptieren bzw. als Ergebnis zurückgeben nennt man Funktionen höherer Ordnung

Kap 3a seite 48-84

## Lambda Kalkül
[comment]: <> (Kapitel 3b)

# Multithreading & Parallele Programmierung
[comment]: <> (Kapitel 4)
## Grundlagen

## Parallele Programmierung in Erlang

## Parallele Programmierung in C++
### Threads
Thread („Faden“) := leichtgewichtige Ausführungseinheit oder Kontrollfluss (Folge von Anweisungen) innerhalb eines sich in Ausführung befindlichen Programms
- Threads teilen sich den Adressraum des ihres Prozesses
- in C++: Instanzen der Klasse std::thread
- führen eine (initiale) Funktion aus

```cpp
#include <thread>
#include <iostream>

void say_hello() {
  std::cout << "Hello Concurrent C++\n";
}

int main() {
  std::thread t(say_hello);
  t.join();
}
```
Alternative Erzeugung von Threads über Lamda Ausdruck: 
```cpp
std::thread t([]() { do_something(); });
```
oder mit Instanz einer Klasse - erfordert Überladen von operator()
```cpp
struct my_task {
  void operator()() const { do_something(); }
};

my_task tsk;
std::thread t1(tsk); // mit Objekt
std::thread t2{ my_task() }; // über Konstruktor
```

Parameter-Übergabe bei Thread-Erzeugung über zusätzliche Argumente des thread-Konstruktors. Vorsicht bei Übergabe von Referenzen, wenn
Eltern-Thread vor dem erzeugten Thread beendet wird.
```cpp
void fun(int n, const std::string& s) {
  for (auto i = 0; i < n; i++)
    std::cout << s << " ";
  std::cout << std::endl;
}
std::thread t(fun, 2, "Hello");
t.join();
```

Warten auf Threads
- t.join() wartet auf Beendigung des Threads t
- blockiert aktuellen Thread
- ohne join() keine Garantie, dass t zur Ausführung kommt
- Freigabe der Ressourcen des Threads
```cpp
std::thread t([]() { do_something(); });
t.join();
```

Hintergrund Threads
- Threads können auch im Hintergrund laufen, ohne dass auf Ende gewartet werden muss
- „abkoppeln“ durch detach()
- Thread läuft danach unter Kontrolle des C++-Laufzeitsystems, join nicht mehr möglich

Thread-Identifikation
- Thread-Identifikator vom Typ `std::thread::id`
- Ermittlung über Methode get_id()
```cpp
void fun() {
  std::cout << "Hello from "
            << std::this_thread::get_id()
            << std::endl;
}
std::thread t(fun);
t.join();
```


### Datenparallele Verarbeitung
### Kommunikation zwischen Threads
### Taskparallelität
...