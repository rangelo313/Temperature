class Temperature
{
	public:
		Temperature();
		Temperature(double degrees = 0.0, char temp = 'C');
		void Input();
		void Show();
		bool Set(double deg, char s);
		//accessor functions, never change
		double GetDegrees() const;
		char GetScale() const;


		bool SetFormat(char f); //mutator
		bool Convert(char sc);
		int Compare(const Temperature &d);
		void Increment(int deg, char sc);// extra credit
	
private:
	double degree;
	char temperature;
	char format;







};
