#pragma once
class CarBuilder;
class CarDocumentationBuilder;

class Builder {
public:
	void virtual setEngine(string engine)=0;
	void virtual setColor(string color)=0;
	void virtual setModel(string model)=0;
	void virtual setBrand(string brand)=0;
};

class Car {
private:
	friend class CarBuilder;
	string engine = "1.5";
	string color = "grey";
	string model = "noname";
	string brand = "noname";
public:
	void show() {
		cout << engine << " : " 
			 << color << " : " 
			 << model << " : " 
			 << brand << endl;
	}
};

class CarDocumentation {

private:
	friend class CarDocumentationBuilder;
	string document="";
public:
	void show() {
		cout << document <<endl;
	}
};

class CarBuilder: public Builder {
	Car car;
public:
	void setEngine(string engine) {
		car.engine = engine;
	}
	void setColor(string color) {
		car.color = color;
	}
	void setModel(string model) {
		car.model = model;
	}
	void setBrand(string brand) {
		car.brand = brand;
	}
	Car getResult() {
		return car;
	}
};

class CarDocumentationBuilder : public Builder {
	CarDocumentation doc;
public:
	void setEngine(string engine) {
		doc.document += "engine: "+engine+" | ";
	}
	void setColor(string color) {
		doc.document += "color: " + color + " | ";
	}
	void setModel(string model) {
		doc.document += "model: " + model + " | ";
	}
	void setBrand(string brand) {
		doc.document += "brand: " + brand + " | ";
	}
	CarDocumentation getResult() {
		return doc;
	}
};

