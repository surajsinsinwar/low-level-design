/*
  A Class Should have only 1 reason to change.

  Marker Entity:

*/

class Marker {
    private:
        string name;
        string color;
        int year;
        int price;

    public:
        Marker(string name, string color, int year, int price) {
            this->name = name;
            this->color = color;
            this->year = year;
            this->price = price;
        }

        int getPrice() {
            return price;
        }
};


class Invoice {
    private:
        Marker marker;
        int quantity;

    public:
        Invoice(Marker marker, int quantity) {
            this->marker = marker;
            this->quantity = quantity;
        }

        int calculateTotal() {
            return marker.getPrice() * quantity;
        }

        void printInvoice() {
            cout << "Total Invoice Amount: " << calculateTotal() << endl;
        }

        void saveToDatabase() {
            // Code to save invoice details to database
        }
};

/*
    Invoice class have more than one reason to change:
    1. Invoice calculation logic changes.
    2. Invoice printing format changes.
    3. Database saving logic changes.

    To handle this, we can separate these responsibilities into different classes.
*/

class Invoice {
    private:
        Marker marker;
        int quantity;
    public:
        Invoice(Marker marker, int quantity) {
            this->marker = marker;
            this->quantity = quantity;
        }

        int InvoiceTotal() {
            return marker.getPrice() * quantity;
        }
};

class InvoicePrinter {
    private:
        Invoice invoice;
    public:
        InvoicePrinter(Invoice invoice) {
            this->invoice = invoice;
        }
        void printInvoice() {
            // Print logic here
        }
};

class InvoiceDao {
    private:
        Invoice invoice;
    public:
        InvoiceDao(Invoice invoice) {
            this->invoice = invoice;
        }
        void saveToDatabase() {
            // Database saving logic here
        }
};


