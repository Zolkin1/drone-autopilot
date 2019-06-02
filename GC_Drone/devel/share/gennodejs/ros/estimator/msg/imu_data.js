// Auto-generated. Do not edit!

// (in-package estimator.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class imu_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.part_name = null;
      this.acceleration = null;
      this.gyro = null;
      this.magentometer = null;
    }
    else {
      if (initObj.hasOwnProperty('part_name')) {
        this.part_name = initObj.part_name
      }
      else {
        this.part_name = '';
      }
      if (initObj.hasOwnProperty('acceleration')) {
        this.acceleration = initObj.acceleration
      }
      else {
        this.acceleration = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('gyro')) {
        this.gyro = initObj.gyro
      }
      else {
        this.gyro = new Array(3).fill(0);
      }
      if (initObj.hasOwnProperty('magentometer')) {
        this.magentometer = initObj.magentometer
      }
      else {
        this.magentometer = new Array(3).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type imu_data
    // Serialize message field [part_name]
    bufferOffset = _serializer.string(obj.part_name, buffer, bufferOffset);
    // Check that the constant length array field [acceleration] has the right length
    if (obj.acceleration.length !== 3) {
      throw new Error('Unable to serialize array field acceleration - length must be 3')
    }
    // Serialize message field [acceleration]
    bufferOffset = _arraySerializer.float32(obj.acceleration, buffer, bufferOffset, 3);
    // Check that the constant length array field [gyro] has the right length
    if (obj.gyro.length !== 3) {
      throw new Error('Unable to serialize array field gyro - length must be 3')
    }
    // Serialize message field [gyro]
    bufferOffset = _arraySerializer.float32(obj.gyro, buffer, bufferOffset, 3);
    // Check that the constant length array field [magentometer] has the right length
    if (obj.magentometer.length !== 3) {
      throw new Error('Unable to serialize array field magentometer - length must be 3')
    }
    // Serialize message field [magentometer]
    bufferOffset = _arraySerializer.float32(obj.magentometer, buffer, bufferOffset, 3);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type imu_data
    let len;
    let data = new imu_data(null);
    // Deserialize message field [part_name]
    data.part_name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [acceleration]
    data.acceleration = _arrayDeserializer.float32(buffer, bufferOffset, 3)
    // Deserialize message field [gyro]
    data.gyro = _arrayDeserializer.float32(buffer, bufferOffset, 3)
    // Deserialize message field [magentometer]
    data.magentometer = _arrayDeserializer.float32(buffer, bufferOffset, 3)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.part_name.length;
    return length + 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'estimator/imu_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2e17c95574e116a26dbc3940045e5e43';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string part_name
    float32[3] acceleration
    float32[3] gyro
    float32[3] magentometer
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new imu_data(null);
    if (msg.part_name !== undefined) {
      resolved.part_name = msg.part_name;
    }
    else {
      resolved.part_name = ''
    }

    if (msg.acceleration !== undefined) {
      resolved.acceleration = msg.acceleration;
    }
    else {
      resolved.acceleration = new Array(3).fill(0)
    }

    if (msg.gyro !== undefined) {
      resolved.gyro = msg.gyro;
    }
    else {
      resolved.gyro = new Array(3).fill(0)
    }

    if (msg.magentometer !== undefined) {
      resolved.magentometer = msg.magentometer;
    }
    else {
      resolved.magentometer = new Array(3).fill(0)
    }

    return resolved;
    }
};

module.exports = imu_data;
