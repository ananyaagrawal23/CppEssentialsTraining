#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract base class for media items
class MediaItem {
protected:
    string name;
    string dateCreated;
    int size;

public:
    MediaItem(const string& nameArg, const string& dateCreatedArg, int sizeArg)
        : name(nameArg), dateCreated(dateCreatedArg), size(sizeArg) {}

    virtual ~MediaItem() {}

    virtual void displayDetails() const = 0;

    const string& getName() const {
        return name;
    }

    const string& getDateCreated() const {
        return dateCreated;
    }

    int getSize() const {
        return size;
    }
};

// Image class, derived from MediaItem
class Image : public MediaItem {
public:
    enum ImageType { JPEG, PNG, GIF };
    ImageType type;

    Image(const string& nameArg, const string& dateCreatedArg, int sizeArg, ImageType typeArg)
        : MediaItem(nameArg, dateCreatedArg, sizeArg), type(typeArg) {}

    void displayDetails() const override {
        cout << "Image Name: " << name << endl;
        cout << "Date Created: " << dateCreated << endl;
        cout << "Size: " << size << " KB" << endl;
        cout << "Type: ";
        switch (type) {
            case JPEG:
                cout << "JPEG" << endl;
                break;
            case PNG:
                cout << "PNG" << endl;
                break;
            case GIF:
                cout << "GIF" << endl;
                break;
            default:
                cout << "Unknown" << endl;
        }
    }
};

// Video class, derived from MediaItem
class Video : public MediaItem {
public:
    enum VideoFormat { MP4, MP3, AVI };
    VideoFormat format;

    Video(const string& nameArg, const string& dateCreatedArg, int sizeArg, VideoFormat formatArg)
        : MediaItem(nameArg, dateCreatedArg, sizeArg), format(formatArg) {}

    void displayDetails() const override {
        cout << "Video Name: " << name << endl;
        cout << "Date Created: " << dateCreated << endl;
        cout << "Size: " << size << " KB" << endl;
        cout << "Format: ";
        switch (format) {
            case MP4:
                cout << "MP4" << endl;
                break;
            case MP3:
                cout << "MP3" << endl;
                break;
            case AVI:
                cout << "AVI" << endl;
                break;
            default:
                cout << "Unknown" << endl;
        }
    }
};

// Class for different applications
class App {
protected:
    string name;

public:
    App(const string& nameArg) : name(nameArg) {}

    virtual void shareMedia(const MediaItem& media) const = 0;
};

// Bluetooth application
class Bluetooth : public App {
public:
    Bluetooth() : App("Bluetooth") {}

    void shareMedia(const MediaItem& media) const override {
        cout << "Sharing " << media.getName() << " via Bluetooth..." << endl;
    }
};

// WhatsApp application
class WhatsApp : public App {
public:
    WhatsApp() : App("WhatsApp") {}

    void shareMedia(const MediaItem& media) const override {
        cout << "Sharing " << media.getName() << " via WhatsApp..." << endl;
    }
};

// Mailbox application
class Mailbox : public App {
public:
    Mailbox() : App("Mailbox") {}

    void shareMedia(const MediaItem& media) const override {
        cout << "Sharing " << media.getName() << " via Mailbox..." << endl;
    }
};

// Gallary class to hold media items
class Gallary {
private:
    vector<MediaItem*> items;

public:
    ~Gallary() {
        for (auto& item : items) {
            delete item;
        }
    }

    void addMediaItem(MediaItem* item) {
        items.push_back(item);
    }

    void displayAllMedia() const {
        cout << "Gallary Contents:\n";
        for (const auto& item : items) {
            item->displayDetails();
            cout << endl;
        }
    }

    void shareMediaViaApp(const MediaItem& media, const App& app) const {
        app.shareMedia(media);
    }

    const MediaItem& getMediaItem(int index) const {
        return *items[index];
    }
};

int main() {
    Gallary Gallary;

    // Adding some sample media items
    Gallary.addMediaItem(new Image("Sunset", "2024-05-12", 256, Image::JPEG));
    Gallary.addMediaItem(new Video("Birthday", "2024-04-28", 1024, Video::MP4));

    // Displaying all media items in the Gallary
    Gallary.displayAllMedia();

    // Sharing a media item via different apps
    Bluetooth bluetooth;
    WhatsApp whatsapp;
    Mailbox mailbox;

    Gallary.shareMediaViaApp(Gallary.getMediaItem(0), bluetooth);
    Gallary.shareMediaViaApp(Gallary.getMediaItem(1), whatsapp);
    Gallary.shareMediaViaApp(Gallary.getMediaItem(0), mailbox);

    return 0;
}
