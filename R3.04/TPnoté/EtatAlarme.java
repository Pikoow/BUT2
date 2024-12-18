public interface EtatAlarme {
    void armer(Alarme alarme);
    void desarmer(Alarme alarme);
    void activer(Alarme alarme);
    void retentir(Alarme alarme);
}
