#include <iostream>
#include <vector>

class RoomBookingService {
public:
    RoomBookingService() {}

    void addRoom(const Room& room)
    {
        rooms_.push_back(room);
    }

    bool bookRoom(int roomId, const std::string& user)
    {
        for (Room& room : rooms_) {
            if (room.id == roomId && !room.isBooked) {
                room.isBooked = true;
                bookings_.push_back({ static_cast<int>(bookings_.size()), roomId, user });
                return true;
            }
        }
        return false;
    }

    // Add other functions to list rooms, available rooms, bookings, etc.

private:
    std::vector<Room> rooms_;
    std::vector<Booking> bookings_;
};

int main()
{
    RoomBookingService service;

    // Add some sample rooms to the service
    service.addRoom({ 1, "Room A", 10, false });
    service.addRoom({ 2, "Room B", 20, false });
    service.addRoom({ 3, "Room C", 15, false });

    // Example: Booking Room 1 for "John Doe"
    if (service.bookRoom(1, "John Doe")) {
        std::cout << "Room booked successfully!" << std::endl;
    } else {
        std::cout << "Room is not available for booking." << std::endl;
    }

    // Example: Booking Room 1 for "Jane Smith"
    if (service.bookRoom(1, "Jane Smith")) {
        std::cout << "Room booked successfully!" << std::endl;
    } else {
        std::cout << "Room is not available for booking." << std::endl;
    }

    return 0;
}
