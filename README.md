# **HỆ THỐNG BÁO CHÁY TỰ ĐỘNG**
> Ngày nay , sự bất cẩn , hay những tình huống bất ngờ đã gây nên việc cháy nhà , cháy rừng.
> Cháy gây ảnh hưởng nặng nề đến con người ( tài sản , thể chất và cả tinh thần). Do đó , chúng ta cần phải cẩn thận hơn trong đời sống hằng ngày , nâng cao ý thức , áp dụng máy móc , công nghệ để trợ giúp trong những tình huống nguy cấp. Từ những yếu tố đó , nhóm em đã hình thành ý tưởng xây dựng " hệ thống báo cháy tự động ".
## **Công cụ lập trình**

- Cài đặt IDE Arduino

## **Nguyên lý hoạt động**
![alt text](https://res.cloudinary.com/http-sv-dut-udn-vn/image/upload/v1656182273/samples/VDK/sdhd_ywmcuf.png)

## **Linh kiện**
- Module Sim800L
- Cảm biến phát hiện lửa
- Còi hú
- Đèn led ( đỏ , xanh)
- Mạch giảm áp LM2596
- Nguồn Adapter 5V-2A
- Dây nối
- Động cơ Servo
- Arduino Uno

## **Sơ đồ lắp mạch**

![alt text](https://res.cloudinary.com/http-sv-dut-udn-vn/image/upload/v1656182274/samples/VDK/SoDoHoatDong_wlrxhc.png)

| Linh kiện | Cách nối chi tiết |
| ------ | ------ |
| Đèn led xanh | Chân âm: GND , Chân dương: D4  |
| Đèn led đỏ | Chân âm: GND , Chân dương: D6  |
| Còi hú | Chân âm: GND , Chân dương: D12  |
| Cảm biến báo cháy | Chân âm: GND , Chân A0: A0, Chân D0: D2, Chân Vcc: 3.3V |
| Động cơ Servo | https://arduinokit.vn/dieu-khien-dong-co-rc-servo-su-dung-arduino/ |
| Module Sim800L | Rx: D11 , Tx: D10, Vcc: 4.1V ( adapter), GND: GND |

**Chú ý: Module Sim800L phải được cấp đúng 4.1V-4.2V**
> Cách giảm áp : Sử dụng mạch giảm áp LM2596

## **Cách chạy chương trình**
- Bước 1: Mở file code source.ino bằng IDE Arduino
- Bước 2: Chọn đúng Port
- Bước 3: Impot thư viện Servo.h
- Bước 4: Upload code và chờ kết quả