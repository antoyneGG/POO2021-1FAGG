class Rectangulo{
    private:
        float largo, ancho;
    public:
        Rectangulo();
        Rectangulo(float largo, float ancho);
        float calcularArea();
        float calcularPerimetro();
        void setLargo(float largo);
        void setAncho(float ancho);
};
