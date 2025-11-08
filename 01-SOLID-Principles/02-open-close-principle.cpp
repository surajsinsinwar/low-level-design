/*
    Open for Extension, Closed for Modification Principle
    -----------------------------------------------------------------------

    OCP is mainly useful when:
        You have a piece of logic that depends on a set of options or behaviors
        ...and you expect that list to change or grow in the future.

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


/*
    This is the code from previous example for comparison
    If in InvoiceDao we need to add functonality to save to a file,
        Adding that functionality would require modifying the InvoiceDao class,
        which violates the Open/Closed Principle.
*/


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
        void saveToFile(string filename) {        // New functionality added, voilating OCP 
            // File saving logic here
        }
};


/*
    We can use an interface to adhere to OCP
*/

class InvoiceDao {
    private:
        Invoice invoice;
    public:
        InvoiceDao(Invoice invoice) {
            this->invoice = invoice;
        }
        virtual void save(Invoice invoice) = 0; // Pure virtual function
};

class DatabaseInvoiceDao : public InvoiceDao {
    public:
        DatabaseInvoiceDao(Invoice invoice) : InvoiceDao(invoice) {}
        void save(Invoice invoice) override {
            // Database saving logic here
        }
};
class FileInvoiceDao : public InvoiceDao {
    public:
        FileInvoiceDao(Invoice invoice) : InvoiceDao(invoice) {}
        void save(Invoice invoice) override {
            // File saving logic here
        }
};