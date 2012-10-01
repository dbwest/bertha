require 'serialport'

describe 'Bertha Sketch' do

  let(:port) { '/dev/cu.usbmodemfa131' }

  let :serial do
    SerialPort.new port, 9600, 8, 1
  end

  before :each do
    serial.read_timeout = 200
    serial.read
  end 

  after :each do
    serial.close
  end

  def send request
    serial.puts request
    serial.gets.chomp
  end

  it 'returns ERROR for an unknown command' do
    send("bad_command").should == 'ERR: unknown command'
  end

  it 'returns correct version number' do
    send("version").should == 'v1.0.0'
  end

  context 'writing to a pin' do

    before :each do
      send("pinMode 13 OUTPUT").should == 'OK: pin 13 set to OUTPUT'
    end

    it 'turns a PIN on' do
      send("digitalWrite 13 1").should == 'OK: pin 13 set to 1'
    end

    it 'turns a PIN off' do
      send("digitalWrite 13 0").should == 'OK: pin 13 set to 0'
    end

  end

end
