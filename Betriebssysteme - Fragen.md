Fragen und Fragestellungen zum Verständnis zur Vorlesung

# Einführung
> Wo sind Betriebssysteme zu finden?


---
> Welches Spektrum decken sie ab?


---
> Welche Arten von Betriebssystemen gibt es?


---
> Welche funktionalen und nichtfunktionalen Eigenschaften spielen dabei eine Rolle?

# Prozesszustände und Zustandsmodelle
> Warum existieren Prozesszustände? Gehen Sie speziell auf die Prozesszustände „bereit“ und „blockiert“ ein.


---
> Welches sind die in praktisch jedem Betriebssystem implementierten (grundlegenden) Prozesszustände?


---
> Nennen Sie Gründe für die Einführung weiterer Prozesszustände. Welche weiteren Prozesszustände sind Ihnen bekannt?


---
> Was ist die Aufgabe von Zustandsmodellen?


---
> Charakterisieren Sie das 3/5- und das 7-Zustandsmodell.


---
> Welchen Zusammenhang gibt es zwischen Prozesszuständen, Zustandsmodellen und der Automatentheorie?


# Scheduler
> Aus welchen Gründen existiert im Betriebssystem die Komponente „Scheduler“ und welche Aufgaben hat diese?

---
> Besitzt jedes Betriebssystem einen Scheduler?

---
> Charakterisieren Sie die Arbeitsweise eines Schedulers.


---
> Welche Vorkommnisse können allgemein zu einer Aktivierung des Schedulers führen?


# Scheduling-Strategie und Scheduling-Algorithmus
> Nennen Sie mögliche strategische Ziele des Scheduling.


---
> Was ist der Unterschied zwischen Scheduling-Strategie und Scheduling-Algorithmus?


# Kontextwechsel
> Was bedeutet es, einen Kontextwechsel auszuführen? Was muss dabei alles getan werden?


---
> Wodurch entstehen die Kosten eines Kontextwechsels und worauf wirken sich diese aus?



# Last und Lastmuster
> Was ist unter „Last“ in einem Computer-System zu verstehen?


---
> Welche charakteristischen Lastmuster könnten dabei vorliegen?


---
> Welcher mögliche Zusammenhang existiert zwischen verschiedenen Lastmustern und verschiedenen Schedulingstrategien?



# Batch-Systeme, Interaktive Systeme und Echtzeitsysteme
> Wodurch sind die genannten Systeme jeweils charakterisiert?



---
> Nennen Sie jeweils geeignete Scheduling-Strategien und charakterisieren Sie diese.



# Privilegierungsebenen
> Welchen Sinn haben Privilegierungsebenen?



---
> Welches sind die grundlegenden, typischerweise verwendeten Privilegierungsebenen?



---
> Wie wirkt sich die Ausführung einer Aktivität in einer bestimmten Privilegierungsebene auf deren Arbeitsweise aus?



# Synchronisation & Kommunikation
> Was versteht man unter einem kritischen Abschnitt?

---
> Warum darf sich in einem kritischen Abschnitt immer nur 1 Thread aufhalten?


---
> Wie können kritische Abschnitte geschützt werden?


---
> Was ist eine exklusiv nutzbare Ressource?


---
> Welchen Zusammenhang gibt es zu kritischen Abschnitten?



---
> Welcher Zusammenhang existiert zwischen „exkluviv nutzbarer Ressource“, „kritischer Abschnitt“ und „race conditions“?


## Semaphor
> Beschreiben Sie einen Semaphor?


---
> Wozu wird er verwendet?


## Monitor (Hoar‘scher)
> Beschreiben Sie einen Monitor?


---
> Wozu wird dieser verwendet?


---
> Welche Vorteile bieten Monitore gegenüber Semaphoren? 



> Was bedeutet Atomarität (von Anweisungen)?


---
> Wo ist Atomarität bei Semaphoren notwendig?


---
> Wie kann Atomarität durch Maschinenbefehle unterstützt werden?


---
> Wozu dienen Bedingungsvariable?
> a) bei Monitoren



> b) Welche Verwendungsmöglichkeiten sind noch denkbar?


---

## Transaktionaler Speicher
> Welche Entwicklungen führten zu Entwicklungsarbeiten bezüglich dieses Konzepts?

---
> Verbirgt sich hinter diesem Konzept eine pessimistische oder eine optimistische Herangehensweise an die Synchronisationsproblematik – und warum?



## Botschaften und botschaftenbasierte Kommunikation
> Unter welchen Bedingungen muss botschaftenbasierte Kommunikation zur Anwendung kommen?


---
> Charakterisieren Sie die 2 elementaren Methoden zur Realisierung botschaftenbasierter Kommunikation!
## Fernaufrufe
> Warum wird unter den entsprechenden Bedingungen (siehe oben) nicht alle Kommunikation über Botschaften abgewickelt – was ist das Besondere an den stattdessen auch verwendeten Prozedurfernaufrufen bzw. Methodenfernaufrufen?


---
> Wie ist die Kommunikation in Mikrokern-Betriebssystemen organisiert?


## Systemaufrufe
> Welchem Zweck dienen Systemaufrufe?

---
> Welche Beispiele von Systemaufrufen sind Ihnen bekannt? – Wozu dienen diese jeweils?


---
> Warum realisieren Systemaufrufe keinen direkten Einsprung in den Betriebssystemkern?


---
> Mit welchen Problemen muss bei der Realisierung von Systemaufrufen umgegangen werden – und wie sehen die Lösungen aus?


## Ereignisse und Ereignismanagement
> Welche Dinge sind im Betriebssystemkontext Ereignisse?

---
> Welche Möglichkeiten gibt es, mit Ereignissen umzugehen?

---
> Welche Vorteile bieten Interrupts (Unterbrechungen)?

---
> Welche drei Modelle gibt es zum Umgang mit Interrupts?

---
> Was sind Interruptvektor, Interruptvektortabelle und Interrupt-Service-Routinen?

---
> Warum und inwieweit ist die Rechner-Hardware in die Interrupt-Bearbeitung involviert?


---
> Was versteht man unter Interrupts auf Anwendungsebene und wie kann damit umgegangen werden?

# Speichermanagement
> Welche Eigenschaften sollte ein idealer Speicher haben?

---
> Warum gibt es stattdessen in der Praxis Speicher-Hierarchien?


---
> Charakterisieren Sie (grob) die bei Speicherhierarchien zum Einsatz kommenden Technologien und Speicherklassen.

---
> Was sollte ein Arbeitsspeicher können?

---
> Aus welchem Grund wurde die Relokation von Prozessen erforderlich – und was wird hierdurch erreicht?

---
> Welche Nachteile bringt die Relokation mit sich?

---
> Wie „funktioniert“ Relokation – technisch gesehen? 

---
> Welche Technik „steckt“ hinter dem Begriff „Swapping“? 


---
> Welche Probleme werden hiermit gelöst – welche nicht? 



---
> Welche neuen Probleme entstehen durch diese Technik (Swapping)?

---
> Welche Verfahren der Speicherverwaltung werden als Realspeicherverwaltung (im Gegensatz zu virtueller Speicherverwaltung) bezeichnet?

---
> Welches sind Grundidee und Zweck des virtuellen Speichers? 


---
> Wie wird virtueller Speicher implementiert? 


---
> Welche Rolle spielt dabei eine Memory Management Unit (MMU)? 


---
> Was versteht man unter „virtueller Speicher“ und „virtuelles Speichermanagement“? 

---
> Was versteht man ganz allgemein unter einem Adressraum? 

---
> Erklären Sie die Begriffe „Adressraum eines Prozesses“, „physischer Adressraum“ und „virtueller Adressraum“ in ausreichender Tiefe. 

---
> Welchem Zweck dient die genannte Abbildung $vm_p$? 


---
> Warum wird für jeden virtuellen Adressraum eine individuelle Abbildung benötigt?


---
> Aus welchem Grund gibt es unbenutzte bzw. undefinierte Adressbereiche? 


---
> Wieso realisiert vm p nur eine partielle Abbildung des virtuellen in den physischen Adressraum? 


---
> Durch welchen Effekt wird durch vm p die Isolation verschiedener virtueller Adressräume erreicht? 


---
> Warum kann es Ausnahmen von dieser Isolation geben – und was soll hierdurch ermöglicht werden? 


---
> Welche Aufgaben hat eine MMU? 


---
> Könnten die Aufgaben einer MMU auch ohne eine solche gelöst werden – und welche Nachteile hätte dies gegebenenfalls?

---
> Was versteht man jeweils unter „Seite“ (page) und Seitenrahmen (page frame) im Kontext der virtuellen Speicherverwaltung? 


---
> Welche Aufgaben hat die Seiten(abbildungs)tabelle? 

---
> Welche Struktur hat ein Seitentabelleneintrag? 

---
> Welche Problemfelder existieren bei der virtuellen Speicherverwaltung (VMM)?

---
> Welche Lösungsmöglichkeiten existieren für die Probleme 1 bis 3?

---
> Was ist unter einem Seitenfehler zu verstehen – und wie kommt ein solcher zustande? 

---
> Was ist ein Seitenfehler-Interrupt – und welchem Zweck dient er? 

---
> Welche Aufgaben lösen jeweils die Hardware bzw. die Software im Zusammenhang mit einem Seitenfehler-Interrupt?

---
> Was ist der Translation Look-aside Buffer und welche Funktion hat er? 

---
> Was ist bei der Verwaltung (Management) des TLB zu beachten? 

---
> Welche prinzipielle Frage stellt sich bei den Seitenaustausch-Algorithmen?

---
> Was versteht man unter der optimalen Seitenaustausch-Strategie – und warum wendet man diese aber nicht an?

---
> Worin besteht die Grundannahme bei der First-In-First-Out-Strategie und was ist von dieser zu halten? 

---
> Welche Vorteile besitzt sie trotzdem? 

---
> Wodurch verbessert die Second-Chance-Strategie die FIFO-Strategie?

---
> Welche Vor- und Nachteile besitzt die Second-Chance-Strategie? 

---
> Wie unterscheidet sich die Grundannahme der LRU-Strategie von derder Second-Chance-Strategie?

---
> Warum sind die Voraussetzungen zur Realisierung von LRU „teuer“ – und wie sehen tatsächliche technische Realisierungen aus? 

---
> Welche Komponenten eines Seitentabelleneintrags sind für die technischen Realisierungen von LRU erforderlich?

---
> Was versteht man unter dem Working Set („Arbeitsmenge“) eines Prozesses?

---
> Von welcher Grundannahme geht die Working-Set-Strategie aus – und welcher Typ von Seiten sind hier Auslagerungskandidaten? 

---
> Wie ist die Arbeitsmenge eines Prozesses definiert? 

---
> Welche Komponenten eines Seitentabelleneintrags sind zu einer technischen Realisierung der Working-Set-Strategie erforderlich? 

---
> Wie ist die Working-Set-Strategie einzuschätzen (Bewertung)? 

---
> Wie funktioniert die WSClock-Strategie?

---
> Welche (schon vorher bekannten) Ideen wurden für die WSClock verwendet? 

---
> Welche Probleme werden mittels Segmentierung gelöst?

---
> Wie funktioniert Segmentierung mit Paging – und wozu ist diese Verfahrensweise gut?


# Dateisysteme
> Wozu werden Dateien benutzt?


---
> Wie ist eine Datei definiert? 


---
> Welche wichtigen Eigenschaften sollten Dateien haben – und warum?


---
> Welche Aufgabe haben Dateimodelle?


---
> Wodurch unterscheiden sich verschiedene Dateimodelle? 


---
> Wozu werden (symbolische) Dateinamen benutzt?


---
> Welche Transparenzeigenschaften können durch die Gestaltung der Dateinamen ausgedrückt werden? 


---
> Was ist ein hierarchischer Namensraum und welche vorteilhafte


---
> Eigenschaft besitzt dieser? 



---
> Welche Vorteile besitzen unstrukturierte Dateien? 


---
> Warum gibt es trotzdem strukturierte Dateien? 


---
> Nennen Sie typische Dateiattribute. 


---
> Was sind Sicherheitsattribute und wie können diese aussehen?


---
> Welche Dateioperationen werden in jedem Dateisystem benötigt?


---
> Welche Funktion haben die Operationen „lseek“ und „mmap“ – und käme man auch ohne diese beiden Funktionen aus?


---
> Welche Aufgaben haben Dateisysteme?


---
> Was ist Ihnen über das physische Layout von Magnetplatten bekannt?


---
> Charakterisieren Sie den Begriff „Sektor“ – warum ist er wichtig?


---
> Welches sind wichtige Parameter von Speichermedien?


---
> Wie unterscheiden sich die Eigenschaften von Magnetplatten und SSDs prinzipiell?


---
> Welche prinzipiellen Management-Datenstrukturen gibt es?


---
> Welche Informationen enthält ein i-Node?



---
> Welche Aufgaben haben Verzeichnisse?


---
> Wie kann ein symbolischer hierarchischer Namensraum dargestellt werden?


---
> Durch welche 2 Formen können freie Speicherbereiche beschrieben werden?


---
> Was wird durch den Superblock beschrieben? 


---
> Welche prinzipiellen Informationen sind hier zu finden?


---
> Beschreiben Sie die einzelnen Schritte verschiedener Dateizugriffsarten


---
> Welche Management-Datenstrukturen sind dabei und zu welchem Zweck beteiligt?

# Netzwerkmanagement
> Wie sind Sockets definiert?

---
> In welchem Zusammenhang werden Sockets benutzt?


---
> Wie kann man sich Sockets – symbolisch gesehen – vorstellen?


---
> Warum treten Sockets immer paarweise auf?


---
> Beschreiben Sie das durch Sockets implementierte Kommunikationsmodell. 


---
> Wie und wozu sind Sockets konfigurierbar? 


---
> Nennen Sie Beispiele für räumlich verteilte Systeme (Hardware) und verteilte Dienste und Anwendungen (Software).


---
> Wozu dient das Socketframework des Betriebssystems?


---
> Aus welchen Ebenen (levels) besteht die Implementierung dieses Frameworks?

# E/A Systeme
> Welche Aufgaben erledigt ein Geräte-Treiber?


---
> Wie muss man sich seine Arbeitsweise vorstellen?


---
> Welcher Zusammenhang besteht zwischen Geräte-Treibern und dem Interrupt-System?


---
> Warum sind die Geräte-Treiber der fehleranfälligste Teil der Betriebssystem-Software?


---
> In welcher Form werden Geräte-Register im Betriebssystem sichtbar?


---
> Wie kann man sich prinzipiell die E/A-Arbeitsweise bei Verwendung eines eigenen E/A-Adressraums vorstellen?


---
> Welche Probleme existieren in diesem Zusammenhang?



---
> Wie funktioniert prinzipiell E/A unter Verwendung von Memory-Mapped-E/A?


---
> Was ist von dem hierbei implementierten Schutzkonzept – auch im Vergleich zu E/A-Adressräumen zu halten?


---
> Was sind in diesem Zusammenhang „nicht-cachebare Seiten“ und wodurch entstehen diese?

# High End Betriebssysteme
> Welche Entwicklungen und Erkenntnisse der Betriebssystem-Forschung zeichnen aktuelle „High-End-Betriebssysteme“ aus?


---
> Welche Ziele sind mit diesen „modernen“ Entwicklungen verbunden – und warum ist dies wichtig und notwendig?


---
> Welche nichtfunktionalen Eigenschaften von Betriebssystemen sind für gesellschaftlich relevante Industriezweige und Einrichtungen von herausgehobener Bedeutung – und warum?


---
> Warum reichen die Sicherheitseigenschaften herkömmlicher Betriebssysteme für heutige Anforderungen nicht mehr aus – und was soll durch verbesserte 

---
> Sicherheitseigenschaften erreicht werden?


---
> Durch welche Maßnahmen wird SELinux zu einem Beispiel eines „zeitgemäßen“ Betriebssystem mit verbesserten Sicherheitseigenschaften?


---
> Welche Rolle spielt der Security-Server bei SELinux?


---
> Wie kann man sich prinzipiell die Sicherheitspolitik von SELinux vorstellen?



---
> Was ist unter Robustheit zu verstehen?


---
> Wodurch unterscheiden sich monolithische und Mikrokern-Architekturen von Betriebssystemen?


---
> Durch welche prinzipiellen Gegebenheiten sind Mikrokern-Architekturen robuster als monolithische Betriebssystemarchitekturen?