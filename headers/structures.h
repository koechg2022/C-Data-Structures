#include <iostream>

#include "useful_functions.h"



// int counter = 1;

namespace data_structures {

	namespace {

		template <typename data_> data_ absolute(data_ value) {
			return ((value < 0) ? (data_) (value * -1) : (data_) value);
		}

		template<typename data_> data_* absolute(data_* value) {
			if (*value < 0) {
				*value = (data_) (*value * -1);
			}
			return value;
		}

		template <typename data_> class node_root {

			protected:
				data_ this_data;
			
			public:

				node_root(){}

				node_root(data_ new_data) : this_data(new_data){
				}

				void set_data(data_ d) {
					this->this_data = d;
				}

				data_ get_data() const {
					return this->this_data;
				}

				data_ &get_data_ref() {
					return this->this_data;
				}

		};

		template <typename data_, typename indx_ = signed long> class numbered_node : public node_root<data_> {

			protected:
				indx_ index;

			public:

				numbered_node() {
				}

				numbered_node(data_ new_data, indx_ index = -1) : node_root<data_>(new_data) {
					this->index = index;
				}

				void set_index(indx_ index) {
					this->index = index;
				}


				indx_ get_index() const {
					return this->index;
				}

		};

		template <typename data_> class linear_node : public node_root<data_> {
			
			protected:
				linear_node<data_>* next_node;
				linear_node<data_>* previous_node;

			public:

				linear_node() {
					this->next_node = nullptr;
				}

				linear_node(data_ new_data, linear_node<data_>* next = nullptr, linear_node<data_>* previous = nullptr) {
					this->this_data = new_data;
					this->next_node = next;
					this->previous_node = previous;
				}

				void set_next(linear_node<data_>* next) {
					this->next_node = next;
				}

				linear_node<data_>* get_next() const {
					return this->next_node;
				}

				void set_previous(linear_node<data_>* previous) {
					this->previous_node = previous;
				}

				linear_node<data_>* get_previous() const {
					return this->previous_node;
				}

		};

	}

	template <typename data_> class linear_linked_list {


		private:
			linear_node<data_> *front, *rear, *frame;
			unsigned long size, frame_index;

			void node_shifter(linear_node<data_>* this_node, unsigned long node_index, signed long by) {
				while ((by != 0) && (this_node != nullptr) && ((node_index != 0) || ((node_index != this->size - 1)))) {
					this_node = (by > 0) ? this_node->get_next() : this_node->get_previous();
					node_index = (by > 0) ? node_index + 1 : node_index - 1;
					by = (by > 0) ? by - 1 : by + 1;
				}
			}

			void frame_shifter(signed long by) {
				while ((by != 0) && (this->frame != nullptr)) {
					this->frame = (by > 0) ? this->frame->get_next() : this->frame->get_previous();
					this->frame_index = (by > 0) ? this->frame_index + 1 : this->frame_index - 1;
					by = (by > 0) ? by - 1 : by + 1;
				}
			}


		public:

			linear_linked_list() {
				this->front = this->rear = this->frame = nullptr;
				this->size = 0;
				// std::cout << "Just called default constructor" << std::endl;
			}


			linear_linked_list(data_ new_data) {
				this->front = this->rear = this->frame = new linear_node<data_>(new_data);
				this->size = 1;
			}


			// Copy Constructor

			linear_linked_list(linear_linked_list<data_>& other_list) {
				if (this == &other_list) {
					return;
				}
				// this->reset();
				// this->front = this->frame = this->rear = nullptr;
				this->size = 0;
				// std::cout << "Copy constructor called. Original length is " << this->size << std::endl;
				// ~linear_linked_list();
				unsigned long index;
				for (index = 0; index < other_list.length(); index = index + 1) {
					this->push(other_list.peek(index));
				}
				// std::cout << "At end of copy constructor call. linear_linked_list has a length of " << this->size << std::endl;
				// std::cout << "At end of copy constructor call, data in this object is :" << std::endl;
				for (index = 0; index < this->size; index = index + 1) {
					std::cout << "\t" << this->peek(index) << std::endl;
				}
			}


			~linear_linked_list() {
				// std::cout << "Inside destructor" << std::endl;
				this->reset();
			}



			// Operator Overloading.

			// Assignment Operators
			// TODO CREATE ASSIGNMENT OPERATORS

			// Comparison operators

			bool operator==(linear_linked_list<data_>& other) {
				if (this == &other) {
					return true;
				}
				if (this->size == other.length()) {
					unsigned long index;
					for (index = 0; index < this->size; index = index + 1) {
						if (this->peek(index) != other.peek(index)) {
							return false;
						}
					}
					return true;
				}
				return false;
			}


			bool operator!=(linear_linked_list<data_>& other) {
				if (this == &other) {
					return false;
				}
				if (this->size != other.length()) {
					return true;
				}
				// the sizes are the same.
				unsigned long index;
				for (index = 0; index < this->size; index = index + 1) {
					if (this->peek(index) != other.peek(index)) {
						return true;
					}
				}
				return false;
			}


			data_& operator [](signed long index) {
				try {
					this->peek(index);
					// frame is now at index.
					return this->frame->get_data_ref();
				}
				catch (std::range_error except) {
					// std::cout << "Illegal index reference " << index << std::endl;
					// exit(EXIT_FAILURE);
					throw except;
				}

			}


			/**
			 * @brief Check if the linear_linked_list is empty or not.
			 * @returns {@code true} if the linear_linked_list, but {@code false} otherwise.
			*/
			bool empty() const {
				return (this->size == 0);
			}


			/**
			 * @brief Get the size of the linked list as an unsigned long.
			 * @returns An {@code unsigned long} of the length of the linear_linked_list.
			*/
			unsigned long length() const {
				return this->size;
			}


			/**
			 * @brief Pushes new data onto the linear_linked_list.
			 * @note A negative index will reference linear_linked_list.length() + index. Just like in python lists.
			 * @param new_data The data to be pushed onto the linear_linked_list.
			 * @param index The index where the data will go on the linear_linked_list.
			*/
			void push(data_ new_data, signed long index = -1) {
				unsigned long add_to;
				// std::cout << "Trying to add \"" << new_data << "\" to index " << index << std::endl;
				if ((useful_functions::absolute(index) > this->size + 1) && (index < 0)) {
					// std::string msg = "For negative 'index', absolute(index) cannot be greater than the size of the linear_linked_list (" + std::to_string(this->size);
					throw std::range_error("Cannot push negative 'index', absolute(index) cannot be greater than the size of the linear_linked_list (" + std::to_string(this->size));
				}
				add_to = (index < 0) ? this->size + 1 - useful_functions::absolute(index) : useful_functions::absolute(index);
				// std::cout << "pushing new data \"" << new_data << "\" to index " << add_to << ", with passed in index of " << index << std::endl;
				if (this->size == 0) {
					// std::cout << "In this->size == 0 branch" << std::endl;
					this->front = this->rear = this->frame = new linear_node<data_>(new_data);
				}
				else {
					// std::cout << "In else branch" << std::endl;
					linear_node<data_>* new_node = new linear_node<data_>(new_data);
					if (add_to == 0) {
						// std::cout << "\tIn add_to == 0 branch" << std::endl;
						// terminal at front
						// std::cout << "1..." << std::endl;
						this->front->set_previous(new_node);
						// std::cout << "2..." << std::endl;
						this->front->get_previous()->set_next(this->front);
						// std::cout << "3..." << std::endl;
						this->front = this->front->get_previous();
						// std::cout << "4..." << std::endl;
						this->frame = this->front;
						// std::cout << "5..." << std::endl;

					}

					else if (add_to == this->size) {
						// terminal at end
						// std::cout << "\tAdding to the end " << std::endl;
						this->rear->set_next(new_node);
						this->rear->get_next()->set_previous(this->rear);
						this->rear = this->rear->get_next();
						this->frame = this->rear;
						// std::cout << "now previous is " << this->rear->get_previous()->get_data() << std::endl;
						// std::cout << "now next is " << ((this->rear->get_next() == nullptr) ? "NULL" : this->rear->get_next()->get_data()) << std::endl;
					}

					else {
						// not terminal. Adding to somewhere in the middle.
						signed long front_to_target, rear_to_target, frame_to_target;
						front_to_target = ((signed long) add_to);
						rear_to_target = ((signed long) add_to) - ((signed long) this->size - 1);
						frame_to_target = ((signed long) add_to) - ((signed long) this->frame_index);
						signed long* distances[] = {&front_to_target, &rear_to_target, &frame_to_target};
						signed long* minimum = useful_functions::min(3, distances, true);
						// std::cout << "\n\nAdding to index : " << add_to << " (" << index << ")" << std::endl;
						// std::cout << "front_to_target : " << front_to_target << std::endl;
						// std::cout << "rear_to_target : " << rear_to_target << std::endl;
						// std::cout << "frame_to_target : " << frame_to_target << std::endl;
						// std::cout << "minimum : " << *minimum << std::endl;
						// std::cout << "frame_info : " << this->frame_index << ".)\t" << this->frame->get_data() << std::endl;
						if (minimum == &front_to_target) {
							this->frame = this->front;
							this->frame_index = 0;
						}
						else if (minimum == &rear_to_target) {
							this->frame = this->rear;
							this->frame_index = this->size - 1;
						}
						this->frame_shifter(*minimum);
						// std::cout << "frame_info : " << this->frame_index << ".)\t" << this->frame->get_data() << std::endl;
						new_node->set_previous(this->frame->get_previous());
						new_node->set_next(this->frame);
						this->frame->get_previous()->set_next(new_node);
						this->frame->set_previous(new_node);

					}
					
				}
				this->size = this->size + 1;
			}


			/**
			 * @brief Check for data on the linear_linked_list. By default, data at the end of the linked list is looked at.
			 * 
			 * @note A negative index will reference linear_linked_list.length() + index. Just like in python lists.
			 * 
			 * @param index The index whose data is to be looked at in the linear_linked_list.
			 * 
			 * @returns The data at the specifed index in the linear_linked_list.
			 * 
			 * @throws std::range_error if the linear_linked_list is empty, or an unreachable index is referenced.
			*/
			data_ peek(signed long index = -1) {
				// std::cout << "Raw peeking index " << index << std::endl;
				if (this->size == 0) {
					throw std::range_error(std::string("Cannot peek empty linked list"));
				}
				unsigned long peek_index;
				if ((useful_functions::absolute(index) > this->size) && (index < 0)) {
					throw std::range_error(std::string("absolute(index) cannot be greater than the size of the linear_linked_list (") + std::to_string(this->size));
				}
				peek_index = (index < 0) ? (((unsigned long) this->size) - useful_functions::absolute(index) ) : ((unsigned long) index);
				// std::cout << "Peek index is " << peek_index << ", and size is " << this->size << std::endl;
				if (peek_index == 0) {
					// std::cout << "about to peek at index 0" << std::endl;
					this->frame = this->front;
					this->frame_index = 0;
				}
				else if (peek_index == this->size - 1) {
					this->frame = this->rear;
					this->frame_index = this->size - 1;
				}
				else {
					signed long shift = (signed long) peek_index - (signed long) this->frame_index;
					this->frame_shifter(shift);
				}
				
				return this->frame->get_data();
			}


			/**
			 * @brief Resets the linear_linked_list to be empty and frees all the data.
			*/
			void reset() {
				// std::cout << "Inside reset method" << std::endl;
				this->frame = this->front;
				while (this->frame != nullptr) {
					this->front = this->frame->get_next();
					// std::cout << "Deleting " << this->frame << std::endl << "\t->\"" << this->frame->get_data() << std::endl;
					delete this->frame;
					this->frame = this->front;
				}
				this->size = 0;
				// std::cout << "Finished reset call" << std::endl;
			}


			/**
			 * @brief This method swaps the data at the first and second index passed in.
			 * 
			 * @param first_index Defaults to 0, and is one of the two indexes whose data
			 * is to be swapped.
			 * 
			 * @param second_index Defaults to -1, and is the other of the two indexes whose data
			 * is to be swapped.
			 * 
			 * @returns void.
			*/
			void swap(signed long first_index = 0, signed long second_index = -1) {
				if (((useful_functions::absolute(second_index) > this->size) && (second_index < 0)) || ((useful_functions::absolute(second_index) > this->size) && (second_index < 0))) {
					std::string msg = "absolute(";
					if (((useful_functions::absolute(second_index) > this->size) && (second_index < 0)) && !((useful_functions::absolute(second_index) > this->size) && (second_index < 0))){
						msg = msg + std::to_string(second_index) + ")";
					}
					else if ((!(useful_functions::absolute(second_index) > this->size) && (second_index < 0)) && ((useful_functions::absolute(second_index) > this->size) && (second_index < 0))) {
						msg = msg + std::to_string(second_index) + ")";
					}
					else {
						msg = msg + std::to_string(second_index) + " & " + "absolute(" + std::to_string(second_index) + ")";
					}
					msg = msg + " must be less than the last index of the linked_list (" + std::to_string(this->size) + ")";
					throw std::range_error(msg);
				}

				if (this->size > 1) {


					unsigned long first_indexx, second_indexx;
					signed long f_index_to_first, f_index_to_frame, f_index_to_rear, s_index_to_first, s_index_to_frame, s_index_to_rear, *first_min, *second_min;;
					first_indexx = (first_index < 0) ? (this->size - useful_functions::absolute(first_index) + 1) : useful_functions::absolute(first_index);
					second_index = (second_index < 0) ? this->size - useful_functions::absolute(second_index) + 1 : useful_functions::absolute(second_index);
					f_index_to_first = (signed long) first_indexx;
					s_index_to_first = (signed long) second_indexx;
					f_index_to_frame = useful_functions::difference((signed long) first_indexx, (signed long) this->frame_index);
					s_index_to_frame = useful_functions::difference((signed long) second_indexx, (signed long) this->frame_index);
					f_index_to_rear = useful_functions::difference((signed long) first_indexx, (signed long) this->size - 1);
					s_index_to_rear = useful_functions::difference((signed long) second_indexx, (signed long) this->size - 1);


					signed long* for_first[] = {&f_index_to_first, &f_index_to_frame, &f_index_to_rear};
					signed long* for_second[] = {&s_index_to_first, &s_index_to_frame, &s_index_to_rear};
					

				}

			}

	};

}