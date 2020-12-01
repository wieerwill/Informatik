Fragen und Fragestellungen zum Verständnis zur Vorlesung

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