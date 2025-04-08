-- MSSV: 23120302
-- Tên: Mã Tuyết Ngân
-- Lớp: 23CTT3


-- tạo csdl
create database QLTGDT
go 
-- sử dụng csdl
use QLTGDT
go 

-- tạo bảng
create table GiaoVien
(
	MaGV char(3),
	HoTen nvarchar(30),
	Luong float,
	Phai nvarchar(3) check(Phai in ('Nam', N'Nữ')),
	NgaySinh date,
	DiaChi nvarchar(40),
	GVQLCM char(3),
	MaBM varchar(5)
	constraint PK_GV primary key (MaGV)
)

create table GV_DT
(
	MaGV char(3),
	DienThoai varchar(10)
	constraint PK_GV_DT primary key (MaGV, DienThoai)
)

create table BoMon
(
	MaBM varchar(5),
	TenBM nvarchar(30),
	Phong char(3),
	DienThoai varchar(10),
	TruongBM char(3),
	MaKhoa varchar(5),
	NgayNhanChuc date
	constraint PK_BM primary key (MaBM)
)

create table Khoa
(
	MaKhoa varchar(5),
	TenKhoa nvarchar(30),
	NamTL int,
	Phong char(3),
	DienThoai varchar(10),
	TruongKhoa char(3),
	NgayNhanChuc date
	constraint PK_Khoa primary key (MaKhoa)
)

create table DeTai
(
	MaDT char(3),
	TenDT nvarchar(50),
	CapQL nvarchar(10),
	KinhPhi float,
	NgayBD date,
	NgayKT date,
	MaCD varchar(5),
	GVCNDT char(3)
	constraint PK_DT primary key (MaDT)
)

create table ChuDe
(
	MaCD varchar(5),
	TenCD nvarchar(40),
	primary key (MaCD)
)

create table CongViec
(
	MaDT char(3),
	STT char(1),
	TenCV nvarchar(40),
	NgayBD date,
	NgayKT date
	constraint PK_CV primary key (MaDT, STT)
)

create table ThamGiaDT
(
	MaGV char(3),
	MaDT char(3), 
	STT char(1),
	PhuCap float,
	KetQua nvarchar(10),
	constraint PK_TGDT primary key (MaGV, MaDT, STT)
)

create table Nguoi_Than
(
	MaGV char(3),
	Ten nvarchar(10),
	NgSinh date,
	Phai nvarchar(3) check(Phai in ('Nam', N'Nữ'))
	constraint PK_NT primary key (MaGV, Ten)
)

-- xác định khóa ngoại 
alter table DeTai add constraint FK_DT_CD foreign key (MaCD) references ChuDe(MaCD)
alter table DeTai add constraint FK_DT_GV foreign key (GVCNDT) references GiaoVien(MaGV)
alter table Nguoi_Than add constraint FK_NT_GV foreign key (MaGV) references GiaoVien(MaGV)
alter table GV_DT add constraint FK_GVDT_GV foreign key (MaGV) references GiaoVien(MaGV)
alter table CongViec add constraint FK_CV_DT foreign key (MaDT) references DeTai(MaDT)
alter table ThamGiaDT add constraint FK_TGDT_CV foreign key (MaDT, STT) references CongViec(MaDT,STT)
alter table Khoa add constraint FK_Khoa_GV foreign key (TruongKhoa) references GiaoVien(MaGV)
alter table BoMon add constraint FK_BM_Khoa foreign key (MaKhoa) references Khoa(MaKhoa)
alter table BoMon add constraint FK_BM_GV foreign key (TruongBM) references GiaoVien(MaGV)
alter table GiaoVien add constraint FK_GV_BM foreign key (MaBM) references BoMon(MaBM)

-- nhập dữ liệu
insert into ChuDe values 
('NCPT', N'Nghiên cứu phát triển'),
('QLGD', N'Quản lý giáo dục'),
('UDCN', N'Ứng dụng công nghệ')

insert into DeTai (MaDT, TenDT, CapQL, KinhPhi, NgayBD, NgayKT, MaCD, GVCNDT) values
('001', N'HTTT quản lý các trường ĐH', N'ĐHQG', 20.0, '2007-10-20', '2008-10-20', 'QLGD' , null),
('002', N'HTTT quản lý giáo vụ cho một Khoa', N'Trường', 20.0, '2000-10-12', '2001-10-12', 'QLGD' , null),
('003', N'Nghiên cứu chế tạo sợi Nanô Platin', N'ĐHQG', 300.0, '2008-05-15', '2010-05-15', 'NCPT' , null),
('004', N'Tạo vật liệu sinh học bằng màng ối người', N'Nhà nước', 100.0, '2007-01-01', '2009-12-31', 'NCPT' , null),
('005', N'Ứng dụng hóa học xanh', N'Trường', 200.0, '2003-10-10', '2004-12-10', 'ƯDCN' , null),
('006', N'Nghiên cứu tế bào gốc', N'Nhà nước', 4000.0, '2006-10-20', '2009-10-20', 'NCPT' , null),
('007', N'HTTT quản lý thư viện ở các trường ĐH', N'Trường', 20.0, '2009-05-10', '2010-05-10', 'QLGD' , null)

insert into CongViec values
('001', '1', N'Khởi tạo và Lập kế hoạch', '2007-10-20', '2008-10-20'),
('001', '2', N'Xác định yêu cầu', '2008-12-21', '2008-03-21'),
('001', '3', N'Phân tích hệ thống', '2008-03-22', '2008-05-22'),
('001', '4', N'Thiết kế hệ thống', '2008-05-23', '2008-06-23'),
('001', '5', N'Cài đặt thử nghiệm', '2008-06-24', '2008-10-20'),
('002', '1', N'Khởi tạo và Lập kế hoạch', '2009-05-10', '2009-07-10'),
('002', '2', N'Xác định yêu cầu', '2009-07-11', '2009-10-11'),
('002', '3', N'Phân tích hệ thống', '2009-10-12', '2009-12-20'),
('002', '4', N'Thiết kế hệ thống', '2009-12-21', '2010-03-22'),
('002', '5', N'Cài đặt thử nghiệm', '2010-03-23', '2010-05-10'),
('006', '1', N'Lấy mẫu', '2006-10-20', '2007-02-20'),
('006', '2', N'Nuôi Cấy', '2007-02-21', '2008-08-21')

insert into GiaoVien values
('001', N'Nguyễn Hoài An', 2000.0, 'Nam', '1973-02-15', N'25/3 Lạc Long Quân, Q.10, TP HCM', null, null),
('002', N'Trần Trà Hương', 2500.0, N'Nữ', '1960-06-20', N'125 Trần Hưng Đạo, Q.1, TP HCM', null, null),
('003', N'Nguyễn Ngọc Ánh', 2200.0, N'Nữ', '1975-05-11', N'12/21 Võ Văn Ngân Thủ Đức, TP HCM', '002', null),
('004', N'Trương Nam Sơn', 2300.0, 'Nam', '1959-06-20', N'215 Lý Thường Kiệt, TP Biên Hòa', null, null),
('005', N'Lý Hoàng Hà', 2500.0, 'Nam', '1954-10-23', N'22/5 Nguyễn Xí, Q.Bình Thạnh, TP HCM', null, null),
('006', N'Trần Bạch Tuyết', 1500.0, N'Nữ', '1980-05-23', N'127 Hùng Vương, TP Mỹ Tho', 004, null),
('007', N'Nguyễn An Trung', 2100.0, 'Nam', '1976-06-05', N'234 3/2, TP Biên Hòa', null, null),
('008', N'Trần Trung Hiếu', 1800.0, 'Nam', '1977-08-06', N'22/11 Lý Thường Kiệt, TP Mỹ Tho', '007', null),
('009', N'Trần Hoàng Nam', 2000.0, 'Nam', '1975-11-22', N'234 Trấn Não, An Phú, TP HCM', '001', null),
('010', N'Phạm Nam Thanh', 1500.0, 'Nam', '1980-12-12', N'221 Hùng Vương, Q.5, TP HCM', '007', null)

insert into Nguoi_Than values
('001', N'Hùng', '1991-01-14', 'Nam'),
('001', N'Thủy', '1994-12-08', N'Nữ'),
('003', N'Hà', '1998-09-03', N'Nữ'),
('003', N'Thu', '1998-09-03', N'Nữ'),
('007', N'Mai', '2003-03-23', N'Nữ'),
('007', N'Vy', '2000-02-14', N'Nữ'),
('008', N'Nam', '1991-05-06', 'Nam'),
('009', N'An', '1996-08-19', 'Nam'),
('010', N'Nguyệt', '2006-01-14', N'Nữ')

insert into GV_DT values 
('001', '0838912112'),
('001', '0903123123'),
('002', '0913454545'),
('003', '0838121212'),
('003', '0903656565'),
('003', '0937125125'),
('006', '0937888888'),
('008', '0653717171'),
('008', '0913232323')

insert into ThamGiaDT values
('001', '002', '1', 0.0, null),
('001', '002', '2', 2.0, null),
('002', '001', '4', 2.0, N'Đạt'),
('003', '001', '1', 1.0, N'Đạt'),
('003', '001', '2', 0.0, N'Đạt'),
('003', '001', '4', 1.0, N'Đạt'),
('003', '002', '2', 0.0, null),
('004', '006', '1', 0.0, N'Đạt'),
('004', '006', '2', 1.0, N'Đạt'),
('006', '006', '2', 1.5, N'Đạt'),
('009', '002', '3', 0.5, null),
('009', '002', '4', 1.5, null)

insert into Khoa values 
('CNTT', N'Công nghệ thông tin', 1995, 'B11', '0838123456', '002', '2005-02-20'),
('HH', N'Hóa học', 1980, 'B41', '0838456456', '007', '2001-10-15'),
('SH', N'Sinh học', 1980, 'B31', '0838454545', '004', '2000-10-11'),
('VL', N'Vật lý', 1976, 'B21', '0838223223', '005', '2003-09-18')

insert into BoMon values 
('CNTT', N'Công nghệ tri thức', 'B15', '0838126126', null, 'CNTT', null),
('HHC', N'Hóa hữu cơ', 'B44', '838222222', null, 'HH', null),
('HL', N'Hóa lý', 'B42', '0838878787', null, 'HH', null),
('HPT', N'Hóa phân tích', 'B43', '0838777777', '007', 'HH', '2007-10-15'),
('HTTT', N'Hệ thống thông tin', 'B13', '0838125125', '002', 'CNTT', '2004-09-20'),
('MMT', N'Mạng máy tính', 'B16', '0838676767', '001', 'CNTT', '2005-05-15'),
('SH', N'Sinh hóa', 'B33', '0838898989', null, 'SH', null),
('VLĐT', N'Vật lý điện tử', 'B23', '0838234234', null, 'VL', null),
('VLƯD', N'Vật lý ứng dụng', 'B24', '0838454545', '005', 'VL', '2006-02-18'),
('VS', N'Vi Sinh', 'B32', '0838909090', '004', 'SH', '2007-01-01')

update DeTai set GVCNDT = '002' where MaDT = '001'
update DeTai set GVCNDT = '002' where MaDT = '002'
update DeTai set GVCNDT = '005' where MaDT = '003'
update DeTai set GVCNDT = '004' where MaDT = '004'
update DeTai set GVCNDT = '007' where MaDT = '005'
update DeTai set GVCNDT = '004' where MaDT = '006'
update DeTai set GVCNDT = '001' where MaDT = '007'

update GiaoVien set MaBM = 'MMT' where MaGV = '001'
update GiaoVien set MaBM = 'HTTT' where MaGV = '002'
update GiaoVien set MaBM = 'HTTT' where MaGV = '003'
update GiaoVien set MaBM = 'VS' where MaGV = '004'
update GiaoVien set MaBM = 'VLĐT' where MaGV = '005'
update GiaoVien set MaBM = 'VS' where MaGV = '006'
update GiaoVien set MaBM = 'HPT' where MaGV = '007'
update GiaoVien set MaBM = 'HPT' where MaGV = '008'
update GiaoVien set MaBM = 'MMT' where MaGV = '009'
update GiaoVien set MaBM = 'HPT' where MaGV = '010'

-- kiểm tra truy vấn
--select * from BoMon
--select * from GiaoVien
--select * from CongViec
--select * from ChuDe
--select * from GV_DT
--select * from Khoa
--select * from DeTai
--select * from Nguoi_Than
--select * from ThamGiaDT

-- Truy vấn
--Đếm số đề tài chủ nhiệm của mỗi bộ môn. Xuất mã, tên, số dtai của mỗi bm. Sắp xếp số đề tài giảm dần
select BM.MaBM, BM.TenBM, count(DT.GVCNDT) as SoDeTaiCN
from BoMon BM
left join GiaoVien GV on BM.MaBM = GV.MaBM
left join DeTai DT on DT.GVCNDT = GV.MaGV
group by BM.MaBM, BM.TenBM
order by SoDeTaiCN desc

--Đếm số đề tài chủ nhiệm của mỗi giảng viên
select GV.MaGV, count(DT.GVCNDT) as SoDeTaiCN
from GiaoVien GV
left join DeTai DT on DT.GVCNDT = GV.MaGV
group by GV.MaGV

--Cho biết magv, hoten giảng viên chủ nhiệm nhiều đề tài nhất
select GV.MaGV, GV.HoTen
from GiaoVien GV
where GV.MaGV in
(
	select DT.GVCNDT--, count(*)
	from DeTai DT 
	group by DT.GVCNDT
	having count(*) >= all 
	(
		select count(*)
		from DeTai DT 
		group by DT.GVCNDT
	)
)

--Cho biết giảng viên nào chủ nhiệm hơn 3 đề tài cấp DHQG
select *
from GiaoVien GV
where GV.MaGV in
(
	select DT.GVCNDT
	from DeTai DT 
	where DT.CapQL = N'ĐHQG'
	group by DT.GVCNDT
	having count(*) > 3
)

--Cho biết giảng viên nữ nào của bm hệ thống ttin chưa chủ nhiệm đề tài
select *
from GiaoVien GV
where GV.MaBM = 'HTTT' and GV.Phai = N'Nữ' and GV.MaGV not in 
(
	select DT.GVCNDT
	from DeTai DT
)

--Cho biết các đề tài được tất cả giảng viên BM hệ thống thông tin tham gia -> k đc có giảng viên nào không tham gia đề tài này
-- cách 1: except
select *
from DeTai DT
where not exists
(	
	select GV.MaGV
	from GiaoVien GV
	join BoMon BM on GV.MaBM = BM.MaBM
	where BM.TenBM = N'Hệ thống thông tin'
	except 
	select TGDT.MaGV
	from ThamGiaDT TGDT
	where TGDT.MaDT = DT.MaDT
)	
-- cách 2: not exists
select *
from DeTai DT
where not exists
(	
	select GV.MaGV
	from GiaoVien GV
	join BoMon BM on GV.MaBM = BM.MaBM
	where BM.TenBM = N'Hệ thống thông tin'
	      and not exists
	(	
		select TGDT.MaGV
		from ThamGiaDT TGDT
		where TGDT.MaDT = DT.MaDT
		      and TGDT.MaGV = GV.MaGV
	)
)	
-- cách 3: not in
select *
from DeTai DT
where not exists
(	
	select GV.MaGV
	from GiaoVien GV
	join BoMon BM on GV.MaBM = BM.MaBM
	where BM.TenBM = N'Hệ thống thông tin'
	      and GV.MaGV not in 
	(	
		select TGDT.MaGV
		from ThamGiaDT TGDT
		where TGDT.MaDT = DT.MaDT
	)
)	

-- cách 4: having
select DT.MaDT, DT.TenDT
from DeTai DT
join ThamGiaDT TGDT on DT.MaDT = TGDT.MaDT
join GiaoVien GV on TGDT.MaGV = GV.MaGV
join BoMon BM on GV.MaBM = BM.MaBM
where BM.TenBM = N'Hệ thống thông tin'
group by DT.MaDT, DT.TenDT
having count(distinct GV.MaGV) = (
    select count(*)
    from GiaoVien GV
    join BoMon BM on GV.MaBM = BM.MaBM
    where BM.TenBM = N'Hệ thống thông tin'
)

--Cho biết các giảng viên bộ môn HTTT tham gia đề tài thuộc tất cả chủ đề -> k đc có chủ đề nào mà không có đề tài giảng viên httt này tham gia 
-- không có chủ đề nào mà họ chưa hướng dẫn đề tài nào
-- cách 1: except
select *
from GiaoVien GV
where GV.MaBM ='HTTT' and not exists
(
	select CD.MaCD
	from ChuDe CD
	except
	select distinct DT.MaCD
	from DeTai DT
	join ThamGiaDT TG on TG.MaDT = DT.MaDT
	where DT.GVCNDT = GV.MaGV
)

-- cách 2: not exists
select *
from GiaoVien GV
where GV.MaBM = 'HTTT' and not exists
(
	select CD.MaCD
	from ChuDe CD
	where not exists
	(
		select distinct DT.MaCD
		from DeTai DT
		join ThamGiaDT TG on TG.MaDT = DT.MaDT
		where DT.GVCNDT = GV.MaGV
			  and CD.MaCD = DT.MaCD
	)
)

-- cách 3: not in
select *
from GiaoVien GV
where GV.MaBM = 'HTTT' and not exists
(
	select CD.MaCD
	from ChuDe CD
	where CD.MaCD not in
	(
		select distinct DT.MaCD
		from DeTai DT
		join ThamGiaDT TG on TG.MaDT = DT.MaDT
		where DT.GVCNDT = GV.MaGV
	)
)

-- cách 4: having
select GV.MaGV, GV.HoTen
from GiaoVien GV
join ThamGiaDT TGDT on GV.MaGV = TGDT.MaGV
join DeTai DT on TGDT.MaDT = DT.MaDT
join ChuDe CD on DT.MaCD = CD.MaCD
where GV.MaBM = 'HTTT'
group by GV.MaGV, GV.HoTen
having count(distinct CD.MaCD) = (
    select count(*)
    from ChuDe
)



