;; Auto-generated. Do not edit!


(when (boundp 'estimator::imu_data)
  (if (not (find-package "ESTIMATOR"))
    (make-package "ESTIMATOR"))
  (shadow 'imu_data (find-package "ESTIMATOR")))
(unless (find-package "ESTIMATOR::IMU_DATA")
  (make-package "ESTIMATOR::IMU_DATA"))

(in-package "ROS")
;;//! \htmlinclude imu_data.msg.html


(defclass estimator::imu_data
  :super ros::object
  :slots (_part_name _acceleration _gyro _magentometer ))

(defmethod estimator::imu_data
  (:init
   (&key
    ((:part_name __part_name) "")
    ((:acceleration __acceleration) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:gyro __gyro) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:magentometer __magentometer) (make-array 3 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _part_name (string __part_name))
   (setq _acceleration __acceleration)
   (setq _gyro __gyro)
   (setq _magentometer __magentometer)
   self)
  (:part_name
   (&optional __part_name)
   (if __part_name (setq _part_name __part_name)) _part_name)
  (:acceleration
   (&optional __acceleration)
   (if __acceleration (setq _acceleration __acceleration)) _acceleration)
  (:gyro
   (&optional __gyro)
   (if __gyro (setq _gyro __gyro)) _gyro)
  (:magentometer
   (&optional __magentometer)
   (if __magentometer (setq _magentometer __magentometer)) _magentometer)
  (:serialization-length
   ()
   (+
    ;; string _part_name
    4 (length _part_name)
    ;; float32[3] _acceleration
    (* 4    3)
    ;; float32[3] _gyro
    (* 4    3)
    ;; float32[3] _magentometer
    (* 4    3)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _part_name
       (write-long (length _part_name) s) (princ _part_name s)
     ;; float32[3] _acceleration
     (dotimes (i 3)
       (sys::poke (elt _acceleration i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[3] _gyro
     (dotimes (i 3)
       (sys::poke (elt _gyro i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[3] _magentometer
     (dotimes (i 3)
       (sys::poke (elt _magentometer i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _part_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _part_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32[3] _acceleration
   (dotimes (i (length _acceleration))
     (setf (elt _acceleration i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[3] _gyro
   (dotimes (i (length _gyro))
     (setf (elt _gyro i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[3] _magentometer
   (dotimes (i (length _magentometer))
     (setf (elt _magentometer i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get estimator::imu_data :md5sum-) "2e17c95574e116a26dbc3940045e5e43")
(setf (get estimator::imu_data :datatype-) "estimator/imu_data")
(setf (get estimator::imu_data :definition-)
      "string part_name
float32[3] acceleration
float32[3] gyro
float32[3] magentometer

")



(provide :estimator/imu_data "2e17c95574e116a26dbc3940045e5e43")


